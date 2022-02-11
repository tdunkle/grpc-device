//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryInterface for NI-RFMXBLUETOOTH
//---------------------------------------------------------------------
#ifndef NIRFMXBLUETOOTH_GRPC_MOCK_LIBRARY_H
#define NIRFMXBLUETOOTH_GRPC_MOCK_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "nirfmxbluetooth_library_interface.h"

namespace ni {
namespace tests {
namespace unit {

class NiRFmxBluetoothMockLibrary : public nirfmxbluetooth_grpc::NiRFmxBluetoothLibraryInterface {
 public:
  MOCK_METHOD(int32, ACPCfgAveraging, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 averagingEnabled, int32 averagingCount), (override));
  MOCK_METHOD(int32, ACPCfgBurstSynchronizationType, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 burstSynchronizationType), (override));
  MOCK_METHOD(int32, ACPCfgNumberOfOffsets, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 numberOfOffsets), (override));
  MOCK_METHOD(int32, ACPCfgOffsetChannelMode, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 offsetChannelMode), (override));
  MOCK_METHOD(int32, ACPFetchAbsolutePowerTrace, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 absolutePower[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ACPFetchMaskTrace, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 limitWithExceptionMask[], float32 limitWithoutExceptionMask[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ACPFetchMeasurementStatus, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, int32* measurementStatus), (override));
  MOCK_METHOD(int32, ACPFetchOffsetMeasurement, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* lowerAbsolutePower, float64* upperAbsolutePower, float64* lowerRelativePower, float64* upperRelativePower, float64* lowerMargin, float64* upperMargin), (override));
  MOCK_METHOD(int32, ACPFetchOffsetMeasurementArray, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64 lowerAbsolutePower[], float64 upperAbsolutePower[], float64 lowerRelativePower[], float64 upperRelativePower[], float64 lowerMargin[], float64 upperMargin[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ACPFetchReferenceChannelPower, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* referenceChannelPower), (override));
  MOCK_METHOD(int32, ACPFetchSpectrum, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 spectrum[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, AbortMeasurements, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, AnalyzeIQ1Waveform, (niRFmxInstrHandle instrumentHandle, char selectorString[], char resultName[], float64 x0, float64 dx, NIComplexSingle iq[], int32 arraySize, int32 reset, int64 reserved), (override));
  MOCK_METHOD(int32, AutoDetectSignal, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout), (override));
  MOCK_METHOD(int32, AutoLevel, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 measurementInterval, float64* referenceLevel), (override));
  MOCK_METHOD(int32, BuildOffsetString, (char selectorString[], int32 offsetNumber, int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildSignalString, (char signalName[], char resultName[], int32 selectorStringLength, char selectorString[]), (override));
  MOCK_METHOD(int32, CfgChannelNumber, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 channelNumber), (override));
  MOCK_METHOD(int32, CfgDataRate, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 dataRate), (override));
  MOCK_METHOD(int32, CfgDigitalEdgeTrigger, (niRFmxInstrHandle instrumentHandle, char selectorString[], char digitalEdgeSource[], int32 digitalEdge, float64 triggerDelay, int32 enableTrigger), (override));
  MOCK_METHOD(int32, CfgExternalAttenuation, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 externalAttenuation), (override));
  MOCK_METHOD(int32, CfgFrequency, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 centerFrequency), (override));
  MOCK_METHOD(int32, CfgFrequencyChannelNumber, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 standard, int32 channelNumber), (override));
  MOCK_METHOD(int32, CfgFrequencyReference, (niRFmxInstrHandle instrumentHandle, char channelName[], char frequencyReferenceSource[], float64 frequencyReferenceFrequency), (override));
  MOCK_METHOD(int32, CfgIQPowerEdgeTrigger, (niRFmxInstrHandle instrumentHandle, char selectorString[], char iqPowerEdgeSource[], int32 iqPowerEdgeSlope, float64 iqPowerEdgeLevel, float64 triggerDelay, int32 triggerMinQuietTimeMode, float64 triggerMinQuietTimeDuration, int32 iqPowerEdgeLevelType, int32 enableTrigger), (override));
  MOCK_METHOD(int32, CfgLEDirectionFinding, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 directionFindingMode, float64 cteLength, float64 cteSlotDuration), (override));
  MOCK_METHOD(int32, CfgMechanicalAttenuation, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 mechanicalAttenuationAuto, float64 mechanicalAttenuationValue), (override));
  MOCK_METHOD(int32, CfgPacketType, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 packetType), (override));
  MOCK_METHOD(int32, CfgPayloadBitPattern, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 payloadBitPattern), (override));
  MOCK_METHOD(int32, CfgPayloadLength, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 payloadLengthMode, int32 payloadLength), (override));
  MOCK_METHOD(int32, CfgRF, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 centerFrequency, float64 referenceLevel, float64 externalAttenuation), (override));
  MOCK_METHOD(int32, CfgRFAttenuation, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 rfAttenuationAuto, float64 rfAttenuationValue), (override));
  MOCK_METHOD(int32, CfgReferenceLevel, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 referenceLevel), (override));
  MOCK_METHOD(int32, CfgSoftwareEdgeTrigger, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 triggerDelay, int32 enableTrigger), (override));
  MOCK_METHOD(int32, CheckMeasurementStatus, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32* isDone), (override));
  MOCK_METHOD(int32, ClearAllNamedResults, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, ClearNamedResult, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, CloneSignalConfiguration, (niRFmxInstrHandle instrumentHandle, char oldSignalName[], char newSignalName[]), (override));
  MOCK_METHOD(int32, Close, (niRFmxInstrHandle instrumentHandle, int32 forceDestroy), (override));
  MOCK_METHOD(int32, Commit, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, CreateSignalConfiguration, (niRFmxInstrHandle instrumentHandle, char signalName[]), (override));
  MOCK_METHOD(int32, DeleteSignalConfiguration, (niRFmxInstrHandle instrumentHandle, char signalName[]), (override));
  MOCK_METHOD(int32, DisableTrigger, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, FrequencyRangeCfgAveraging, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 averagingEnabled, int32 averagingCount), (override));
  MOCK_METHOD(int32, FrequencyRangeCfgSpan, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 span), (override));
  MOCK_METHOD(int32, FrequencyRangeFetchMeasurement, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* highFrequency, float64* lowFrequency), (override));
  MOCK_METHOD(int32, FrequencyRangeFetchSpectrum, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 spectrum[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAllNamedResultNames, (niRFmxInstrHandle instrumentHandle, char selectorString[], char resultNames[], int32 resultNamesBufferSize, int32* actualResultNamesSize, int32* defaultResultExists), (override));
  MOCK_METHOD(int32, GetAttributeF32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeF32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeF64, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeF64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeI16, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int16* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeI64, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeI8, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI8Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeNIComplexDoubleArray, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexDouble attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeNIComplexSingleArray, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexSingle attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeString, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 arraySize, char attrVal[]), (override));
  MOCK_METHOD(int32, GetAttributeU16, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt16* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeU32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeU32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeU64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt64 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeU8, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeU8Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetError, (niRFmxInstrHandle instrumentHandle, int32* errorCode, int32 errorDescriptionBufferSize, char errorDescription[]), (override));
  MOCK_METHOD(int32, GetErrorString, (niRFmxInstrHandle instrumentHandle, int32 errorCode, int32 errorDescriptionBufferSize, char errorDescription[]), (override));
  MOCK_METHOD(int32, Initialize, (char resourceName[], char optionString[], niRFmxInstrHandle* handleOut, int32* isNewSession), (override));
  MOCK_METHOD(int32, InitializeFromNIRFSASession, (uInt32 nirfsaSession, niRFmxInstrHandle* handleOut), (override));
  MOCK_METHOD(int32, Initiate, (niRFmxInstrHandle instrumentHandle, char selectorString[], char resultName[]), (override));
  MOCK_METHOD(int32, ModAccCfgAveraging, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 averagingEnabled, int32 averagingCount), (override));
  MOCK_METHOD(int32, ModAccCfgBurstSynchronizationType, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 burstSynchronizationType), (override));
  MOCK_METHOD(int32, ModAccFetchConstellationTrace, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, NIComplexSingle constellation[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ModAccFetchDEVM, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* peakRMSDEVMMaximum, float64* peakDEVMMaximum, float64* ninetyninePercentDEVM), (override));
  MOCK_METHOD(int32, ModAccFetchDEVMMagnitudeError, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* averageRMSMagnitudeErrorMean, float64* peakRMSMagnitudeErrorMaximum), (override));
  MOCK_METHOD(int32, ModAccFetchDEVMPerSymbolTrace, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float32 devmPerSymbol[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ModAccFetchDEVMPhaseError, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* averageRMSPhaseErrorMean, float64* peakRMSPhaseErrorMaximum), (override));
  MOCK_METHOD(int32, ModAccFetchDemodulatedBitTrace, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, int8 demodulatedBits[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ModAccFetchDf1, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* df1avgMaximum, float64* df1avgMinimum), (override));
  MOCK_METHOD(int32, ModAccFetchDf1maxTrace, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float32 time[], float32 df1max[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ModAccFetchDf2, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* df2avgMinimum, float64* percentageOfSymbolsAboveDf2maxThreshold), (override));
  MOCK_METHOD(int32, ModAccFetchDf2maxTrace, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float32 time[], float32 df2max[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ModAccFetchFrequencyErrorBR, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* initialFrequencyErrorMaximum, float64* peakFrequencyDriftMaximum, float64* peakFrequencyDriftRateMaximum), (override));
  MOCK_METHOD(int32, ModAccFetchFrequencyErrorEDR, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* headerFrequencyErrorWiMaximum, float64* peakFrequencyErrorWiPlusW0Maximum, float64* peakFrequencyErrorW0Maximum), (override));
  MOCK_METHOD(int32, ModAccFetchFrequencyErrorLE, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* peakFrequencyErrorMaximum, float64* initialFrequencyDriftMaximum, float64* peakFrequencyDriftMaximum, float64* peakFrequencyDriftRateMaximum), (override));
  MOCK_METHOD(int32, ModAccFetchFrequencyErrorTraceBR, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float32 time[], float32 frequencyError[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ModAccFetchFrequencyErrorTraceLE, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float32 time[], float32 frequencyError[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ModAccFetchFrequencyErrorWiPlusW0TraceEDR, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float32 time[], float32 frequencyErrorWiPlusW0[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ModAccFetchFrequencyTrace, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 frequency[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ModAccFetchRMSDEVMTrace, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float32 rmsdevm[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, ResetAttribute, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID), (override));
  MOCK_METHOD(int32, ResetToDefault, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, SelectMeasurements, (niRFmxInstrHandle instrumentHandle, char selectorString[], uInt32 measurements, int32 enableAllTraces), (override));
  MOCK_METHOD(int32, SendSoftwareEdgeTrigger, (niRFmxInstrHandle instrumentHandle), (override));
  MOCK_METHOD(int32, SetAttributeF32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeF32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeF64, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeF64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeI16, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int16 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeI64, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeI8, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI8Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeNIComplexDoubleArray, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexDouble attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeNIComplexSingleArray, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexSingle attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeString, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, char attrVal[]), (override));
  MOCK_METHOD(int32, SetAttributeU16, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt16 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeU32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeU32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeU64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt64 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeU8, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeU8Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, TXPCfgAveraging, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 averagingEnabled, int32 averagingCount), (override));
  MOCK_METHOD(int32, TXPCfgBurstSynchronizationType, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 burstSynchronizationType), (override));
  MOCK_METHOD(int32, TXPFetchEDRPowers, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* edrgfskAveragePowerMean, float64* edrdpskAveragePowerMean, float64* edr_DPSK_GFSKAveragePowerRatioMean), (override));
  MOCK_METHOD(int32, TXPFetchLECTEReferencePeriodPowers, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* referencePeriodAveragePowerMean, float64* referencePeriodPeakAbsolutePowerDeviationMaximum), (override));
  MOCK_METHOD(int32, TXPFetchLECTETransmitSlotPowers, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* transmitSlotAveragePowerMean, float64* transmitSlotPeakAbsolutePowerDeviationMaximum), (override));
  MOCK_METHOD(int32, TXPFetchLECTETransmitSlotPowersArray, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64 transmitSlotAveragePowerMean[], float64 transmitSlotPeakAbsolutePowerDeviationMaximum[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, TXPFetchPowerTrace, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 power[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, TXPFetchPowers, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* averagePowerMean, float64* averagePowerMaximum, float64* averagePowerMinimum, float64* peakToAveragePowerRatioMaximum), (override));
  MOCK_METHOD(int32, WaitForAcquisitionComplete, (niRFmxInstrHandle instrumentHandle, float64 timeout), (override));
  MOCK_METHOD(int32, WaitForMeasurementComplete, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout), (override));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NIRFMXBLUETOOTH_GRPC_MOCK_LIBRARY_H
