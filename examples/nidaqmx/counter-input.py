r"""Measure frequency using one counter on a Counter Input Channel.

The gRPC API is built from the C API. NI-DAQmx documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\NI-DAQ\docs\cdaqmx.chm

Getting Started:

To run this example, install "NI-DAQmx Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-daqmx.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI DAQmx gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-DAQMX-C-Function-Reference

To run this example without hardware: create a simulated device in NI MAX on the server (Windows
only).

Running from command line:

Server machine's IP address, port number, and counter name can be passed as separate command line
arguments.
  > python counter-input.py <server_address> <port_number> <counter_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "Dev1/ctr0" as the counter name.
"""

import sys

import grpc
import nidaqmx_pb2 as nidaqmx_types
import nidaqmx_pb2_grpc as grpc_nidaqmx

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
COUNTER_NAME = "Dev1/ctr0"

if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    COUNTER_NAME = sys.argv[3]

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nidaqmx.NiDAQmxStub(channel)
task = None


def check_for_warning(response):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nidaqmx_types.ErrorMessageRequest(error_code=response.status)
        )
        sys.stderr.write(f"{warning_message.error_message}\nWarning status: {response.status}\n")

try:
    response = client.CreateTask(nidaqmx_types.CreateTaskRequest(session_name="my task"))
    task = response.task

    client.CreateCIFreqChan(
        nidaqmx_types.CreateCIFreqChanRequest(
            task=task,
            counter=COUNTER_NAME,
            min_val=1.192093,
            max_val=10000000,
            units=nidaqmx_types.FREQUENCY_UNITS3_HZ,
            edge=nidaqmx_types.EDGE1_RISING,
            meas_method=nidaqmx_types.COUNTER_FREQUENCY_METHOD_LOW_FREQ_1_CTR,
            meas_time=0.001,
            divisor=4,
        )
    )

    start_task_response = client.StartTask(nidaqmx_types.StartTaskRequest(task=task))
    check_for_warning(start_task_response)

    response = client.ReadCounterScalarF64(
        nidaqmx_types.ReadCounterScalarF64Request(task=task, timeout=10.0)
    )
    check_for_warning(response)
    print(f"Frequency: {response.value} Hz")
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    for entry in rpc_error.trailing_metadata() or []:
        if entry.key == "ni-error":
            value = entry.value if isinstance(entry.value, str) else entry.value.decode("utf-8")
            error_message += f"\nError status: {value}"
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    print(f"{error_message}")
finally:
    if task:
        clear_task_response = client.ClearTask(nidaqmx_types.ClearTaskRequest(task=task))
        check_for_warning(clear_task_response)
