//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-DMM Metadata
//---------------------------------------------------------------------
#include "nidmm_library.h"

#if defined(_MSC_VER)
static const char* kLibraryName = "nidmm_64.dll";
#else
static const char* kLibraryName = "libnidmm.so";
#endif

namespace nidmm_grpc {

NiDMMLibrary::NiDMMLibrary() : shared_library_(kLibraryName)
{
  shared_library_.load();
  bool loaded = shared_library_.is_loaded();
  memset(&function_pointers_, 0, sizeof(function_pointers_));
  if (!loaded) {
    return;
  }
  function_pointers_.Abort = reinterpret_cast<AbortPtr>(shared_library_.get_function_pointer("niDMM_Abort"));
  function_pointers_.ConfigureMeasurementAbsolute = reinterpret_cast<ConfigureMeasurementAbsolutePtr>(shared_library_.get_function_pointer("niDMM_ConfigureMeasurementAbsolute"));
  function_pointers_.ConfigureMeasurementDigits = reinterpret_cast<ConfigureMeasurementDigitsPtr>(shared_library_.get_function_pointer("niDMM_ConfigureMeasurementDigits"));
  function_pointers_.ConfigureMultiPoint = reinterpret_cast<ConfigureMultiPointPtr>(shared_library_.get_function_pointer("niDMM_ConfigureMultiPoint"));
  function_pointers_.ConfigureRTDCustom = reinterpret_cast<ConfigureRTDCustomPtr>(shared_library_.get_function_pointer("niDMM_ConfigureRTDCustom"));
  function_pointers_.ConfigureRTDType = reinterpret_cast<ConfigureRTDTypePtr>(shared_library_.get_function_pointer("niDMM_ConfigureRTDType"));
  function_pointers_.ConfigureThermistorCustom = reinterpret_cast<ConfigureThermistorCustomPtr>(shared_library_.get_function_pointer("niDMM_ConfigureThermistorCustom"));
  function_pointers_.ConfigureThermocouple = reinterpret_cast<ConfigureThermocouplePtr>(shared_library_.get_function_pointer("niDMM_ConfigureThermocouple"));
  function_pointers_.ConfigureTrigger = reinterpret_cast<ConfigureTriggerPtr>(shared_library_.get_function_pointer("niDMM_ConfigureTrigger"));
  function_pointers_.ConfigureWaveformAcquisition = reinterpret_cast<ConfigureWaveformAcquisitionPtr>(shared_library_.get_function_pointer("niDMM_ConfigureWaveformAcquisition"));
  function_pointers_.Disable = reinterpret_cast<DisablePtr>(shared_library_.get_function_pointer("niDMM_Disable"));
  function_pointers_.ExportAttributeConfigurationBuffer = reinterpret_cast<ExportAttributeConfigurationBufferPtr>(shared_library_.get_function_pointer("niDMM_ExportAttributeConfigurationBuffer"));
  function_pointers_.ExportAttributeConfigurationFile = reinterpret_cast<ExportAttributeConfigurationFilePtr>(shared_library_.get_function_pointer("niDMM_ExportAttributeConfigurationFile"));
  function_pointers_.Fetch = reinterpret_cast<FetchPtr>(shared_library_.get_function_pointer("niDMM_Fetch"));
  function_pointers_.FetchMultiPoint = reinterpret_cast<FetchMultiPointPtr>(shared_library_.get_function_pointer("niDMM_FetchMultiPoint"));
  function_pointers_.FetchWaveform = reinterpret_cast<FetchWaveformPtr>(shared_library_.get_function_pointer("niDMM_FetchWaveform"));
  function_pointers_.GetAttributeViBoolean = reinterpret_cast<GetAttributeViBooleanPtr>(shared_library_.get_function_pointer("niDMM_GetAttributeViBoolean"));
  function_pointers_.GetAttributeViInt32 = reinterpret_cast<GetAttributeViInt32Ptr>(shared_library_.get_function_pointer("niDMM_GetAttributeViInt32"));
  function_pointers_.GetAttributeViReal64 = reinterpret_cast<GetAttributeViReal64Ptr>(shared_library_.get_function_pointer("niDMM_GetAttributeViReal64"));
  function_pointers_.GetAttributeViString = reinterpret_cast<GetAttributeViStringPtr>(shared_library_.get_function_pointer("niDMM_GetAttributeViString"));
  function_pointers_.GetCalDateAndTime = reinterpret_cast<GetCalDateAndTimePtr>(shared_library_.get_function_pointer("niDMM_GetCalDateAndTime"));
  function_pointers_.GetDevTemp = reinterpret_cast<GetDevTempPtr>(shared_library_.get_function_pointer("niDMM_GetDevTemp"));
  function_pointers_.GetError = reinterpret_cast<GetErrorPtr>(shared_library_.get_function_pointer("niDMM_GetError"));
  function_pointers_.GetExtCalRecommendedInterval = reinterpret_cast<GetExtCalRecommendedIntervalPtr>(shared_library_.get_function_pointer("niDMM_GetExtCalRecommendedInterval"));
  function_pointers_.GetLastCalTemp = reinterpret_cast<GetLastCalTempPtr>(shared_library_.get_function_pointer("niDMM_GetLastCalTemp"));
  function_pointers_.GetSelfCalSupported = reinterpret_cast<GetSelfCalSupportedPtr>(shared_library_.get_function_pointer("niDMM_GetSelfCalSupported"));
  function_pointers_.ImportAttributeConfigurationBuffer = reinterpret_cast<ImportAttributeConfigurationBufferPtr>(shared_library_.get_function_pointer("niDMM_ImportAttributeConfigurationBuffer"));
  function_pointers_.ImportAttributeConfigurationFile = reinterpret_cast<ImportAttributeConfigurationFilePtr>(shared_library_.get_function_pointer("niDMM_ImportAttributeConfigurationFile"));
  function_pointers_.InitWithOptions = reinterpret_cast<InitWithOptionsPtr>(shared_library_.get_function_pointer("niDMM_InitWithOptions"));
  function_pointers_.Initiate = reinterpret_cast<InitiatePtr>(shared_library_.get_function_pointer("niDMM_Initiate"));
  function_pointers_.LockSession = reinterpret_cast<LockSessionPtr>(shared_library_.get_function_pointer("niDMM_LockSession"));
  function_pointers_.PerformOpenCableComp = reinterpret_cast<PerformOpenCableCompPtr>(shared_library_.get_function_pointer("niDMM_PerformOpenCableComp"));
  function_pointers_.PerformShortCableComp = reinterpret_cast<PerformShortCableCompPtr>(shared_library_.get_function_pointer("niDMM_PerformShortCableComp"));
  function_pointers_.Read = reinterpret_cast<ReadPtr>(shared_library_.get_function_pointer("niDMM_Read"));
  function_pointers_.ReadMultiPoint = reinterpret_cast<ReadMultiPointPtr>(shared_library_.get_function_pointer("niDMM_ReadMultiPoint"));
  function_pointers_.ReadStatus = reinterpret_cast<ReadStatusPtr>(shared_library_.get_function_pointer("niDMM_ReadStatus"));
  function_pointers_.ReadWaveform = reinterpret_cast<ReadWaveformPtr>(shared_library_.get_function_pointer("niDMM_ReadWaveform"));
  function_pointers_.ResetWithDefaults = reinterpret_cast<ResetWithDefaultsPtr>(shared_library_.get_function_pointer("niDMM_ResetWithDefaults"));
  function_pointers_.SelfCal = reinterpret_cast<SelfCalPtr>(shared_library_.get_function_pointer("niDMM_SelfCal"));
  function_pointers_.SendSoftwareTrigger = reinterpret_cast<SendSoftwareTriggerPtr>(shared_library_.get_function_pointer("niDMM_SendSoftwareTrigger"));
  function_pointers_.SetAttributeViBoolean = reinterpret_cast<SetAttributeViBooleanPtr>(shared_library_.get_function_pointer("niDMM_SetAttributeViBoolean"));
  function_pointers_.SetAttributeViInt32 = reinterpret_cast<SetAttributeViInt32Ptr>(shared_library_.get_function_pointer("niDMM_SetAttributeViInt32"));
  function_pointers_.SetAttributeViReal64 = reinterpret_cast<SetAttributeViReal64Ptr>(shared_library_.get_function_pointer("niDMM_SetAttributeViReal64"));
  function_pointers_.SetAttributeViString = reinterpret_cast<SetAttributeViStringPtr>(shared_library_.get_function_pointer("niDMM_SetAttributeViString"));
  function_pointers_.UnlockSession = reinterpret_cast<UnlockSessionPtr>(shared_library_.get_function_pointer("niDMM_UnlockSession"));
  function_pointers_.close = reinterpret_cast<closePtr>(shared_library_.get_function_pointer("niDMM_close"));
  function_pointers_.error_message = reinterpret_cast<error_messagePtr>(shared_library_.get_function_pointer("niDMM_error_message"));
  function_pointers_.reset = reinterpret_cast<resetPtr>(shared_library_.get_function_pointer("niDMM_reset"));
  function_pointers_.self_test = reinterpret_cast<self_testPtr>(shared_library_.get_function_pointer("niDMM_self_test"));
}

NiDMMLibrary::~NiDMMLibrary()
{
}

::grpc::Status NiDMMLibrary::check_function_exists(std::string functionName)
{
  return shared_library_.function_exists(functionName.c_str())
    ? ::grpc::Status::OK
    : ::grpc::Status(::grpc::NOT_FOUND, "Could not find the function " + functionName);
}

ViStatus NiDMMLibrary::Abort(ViSession vi)
{
  if (!function_pointers_.Abort) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_Abort.");
  }
#if defined(_MSC_VER)
  return niDMM_Abort(vi);
#else
  return function_pointers_.Abort(vi);
#endif
}

ViStatus NiDMMLibrary::ConfigureMeasurementAbsolute(ViSession vi, ViInt32 measurementFunction, ViReal64 range, ViReal64 resolutionAbsolute)
{
  if (!function_pointers_.ConfigureMeasurementAbsolute) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ConfigureMeasurementAbsolute.");
  }
#if defined(_MSC_VER)
  return niDMM_ConfigureMeasurementAbsolute(vi, measurementFunction, range, resolutionAbsolute);
#else
  return function_pointers_.ConfigureMeasurementAbsolute(vi, measurementFunction, range, resolutionAbsolute);
#endif
}

ViStatus NiDMMLibrary::ConfigureMeasurementDigits(ViSession vi, ViInt32 measurementFunction, ViReal64 range, ViReal64 resolutionDigits)
{
  if (!function_pointers_.ConfigureMeasurementDigits) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ConfigureMeasurementDigits.");
  }
#if defined(_MSC_VER)
  return niDMM_ConfigureMeasurementDigits(vi, measurementFunction, range, resolutionDigits);
#else
  return function_pointers_.ConfigureMeasurementDigits(vi, measurementFunction, range, resolutionDigits);
#endif
}

ViStatus NiDMMLibrary::ConfigureMultiPoint(ViSession vi, ViInt32 triggerCount, ViInt32 sampleCount, ViInt32 sampleTrigger, ViReal64 sampleInterval)
{
  if (!function_pointers_.ConfigureMultiPoint) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ConfigureMultiPoint.");
  }
#if defined(_MSC_VER)
  return niDMM_ConfigureMultiPoint(vi, triggerCount, sampleCount, sampleTrigger, sampleInterval);
#else
  return function_pointers_.ConfigureMultiPoint(vi, triggerCount, sampleCount, sampleTrigger, sampleInterval);
#endif
}

ViStatus NiDMMLibrary::ConfigureRTDCustom(ViSession vi, ViReal64 rtdA, ViReal64 rtdB, ViReal64 rtdC)
{
  if (!function_pointers_.ConfigureRTDCustom) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ConfigureRTDCustom.");
  }
#if defined(_MSC_VER)
  return niDMM_ConfigureRTDCustom(vi, rtdA, rtdB, rtdC);
#else
  return function_pointers_.ConfigureRTDCustom(vi, rtdA, rtdB, rtdC);
#endif
}

ViStatus NiDMMLibrary::ConfigureRTDType(ViSession vi, ViInt32 rtdType, ViReal64 rtdResistance)
{
  if (!function_pointers_.ConfigureRTDType) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ConfigureRTDType.");
  }
#if defined(_MSC_VER)
  return niDMM_ConfigureRTDType(vi, rtdType, rtdResistance);
#else
  return function_pointers_.ConfigureRTDType(vi, rtdType, rtdResistance);
#endif
}

ViStatus NiDMMLibrary::ConfigureThermistorCustom(ViSession vi, ViReal64 thermistorA, ViReal64 thermistorB, ViReal64 thermistorC)
{
  if (!function_pointers_.ConfigureThermistorCustom) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ConfigureThermistorCustom.");
  }
#if defined(_MSC_VER)
  return niDMM_ConfigureThermistorCustom(vi, thermistorA, thermistorB, thermistorC);
#else
  return function_pointers_.ConfigureThermistorCustom(vi, thermistorA, thermistorB, thermistorC);
#endif
}

ViStatus NiDMMLibrary::ConfigureThermocouple(ViSession vi, ViInt32 thermocoupleType, ViInt32 referenceJunctionType)
{
  if (!function_pointers_.ConfigureThermocouple) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ConfigureThermocouple.");
  }
#if defined(_MSC_VER)
  return niDMM_ConfigureThermocouple(vi, thermocoupleType, referenceJunctionType);
#else
  return function_pointers_.ConfigureThermocouple(vi, thermocoupleType, referenceJunctionType);
#endif
}

ViStatus NiDMMLibrary::ConfigureTrigger(ViSession vi, ViInt32 triggerSource, ViReal64 triggerDelay)
{
  if (!function_pointers_.ConfigureTrigger) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ConfigureTrigger.");
  }
#if defined(_MSC_VER)
  return niDMM_ConfigureTrigger(vi, triggerSource, triggerDelay);
#else
  return function_pointers_.ConfigureTrigger(vi, triggerSource, triggerDelay);
#endif
}

ViStatus NiDMMLibrary::ConfigureWaveformAcquisition(ViSession vi, ViInt32 measurementFunction, ViReal64 range, ViReal64 rate, ViInt32 waveformPoints)
{
  if (!function_pointers_.ConfigureWaveformAcquisition) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ConfigureWaveformAcquisition.");
  }
#if defined(_MSC_VER)
  return niDMM_ConfigureWaveformAcquisition(vi, measurementFunction, range, rate, waveformPoints);
#else
  return function_pointers_.ConfigureWaveformAcquisition(vi, measurementFunction, range, rate, waveformPoints);
#endif
}

ViStatus NiDMMLibrary::Disable(ViSession vi)
{
  if (!function_pointers_.Disable) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_Disable.");
  }
#if defined(_MSC_VER)
  return niDMM_Disable(vi);
#else
  return function_pointers_.Disable(vi);
#endif
}

ViStatus NiDMMLibrary::ExportAttributeConfigurationBuffer(ViSession vi, ViInt32 size, ViInt8 configuration[])
{
  if (!function_pointers_.ExportAttributeConfigurationBuffer) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ExportAttributeConfigurationBuffer.");
  }
#if defined(_MSC_VER)
  return niDMM_ExportAttributeConfigurationBuffer(vi, size, configuration);
#else
  return function_pointers_.ExportAttributeConfigurationBuffer(vi, size, configuration);
#endif
}

ViStatus NiDMMLibrary::ExportAttributeConfigurationFile(ViSession vi, ViConstString filePath)
{
  if (!function_pointers_.ExportAttributeConfigurationFile) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ExportAttributeConfigurationFile.");
  }
#if defined(_MSC_VER)
  return niDMM_ExportAttributeConfigurationFile(vi, filePath);
#else
  return function_pointers_.ExportAttributeConfigurationFile(vi, filePath);
#endif
}

ViStatus NiDMMLibrary::Fetch(ViSession vi, ViInt32 maximumTime, ViReal64* reading)
{
  if (!function_pointers_.Fetch) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_Fetch.");
  }
#if defined(_MSC_VER)
  return niDMM_Fetch(vi, maximumTime, reading);
#else
  return function_pointers_.Fetch(vi, maximumTime, reading);
#endif
}

ViStatus NiDMMLibrary::FetchMultiPoint(ViSession vi, ViInt32 maximumTime, ViInt32 arraySize, ViReal64 readingArray[], ViInt32* actualNumberOfPoints)
{
  if (!function_pointers_.FetchMultiPoint) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_FetchMultiPoint.");
  }
#if defined(_MSC_VER)
  return niDMM_FetchMultiPoint(vi, maximumTime, arraySize, readingArray, actualNumberOfPoints);
#else
  return function_pointers_.FetchMultiPoint(vi, maximumTime, arraySize, readingArray, actualNumberOfPoints);
#endif
}

ViStatus NiDMMLibrary::FetchWaveform(ViSession vi, ViInt32 maximumTime, ViInt32 arraySize, ViReal64 waveformArray[], ViInt32* actualNumberOfPoints)
{
  if (!function_pointers_.FetchWaveform) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_FetchWaveform.");
  }
#if defined(_MSC_VER)
  return niDMM_FetchWaveform(vi, maximumTime, arraySize, waveformArray, actualNumberOfPoints);
#else
  return function_pointers_.FetchWaveform(vi, maximumTime, arraySize, waveformArray, actualNumberOfPoints);
#endif
}

ViStatus NiDMMLibrary::GetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean* attributeValue)
{
  if (!function_pointers_.GetAttributeViBoolean) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_GetAttributeViBoolean.");
  }
#if defined(_MSC_VER)
  return niDMM_GetAttributeViBoolean(vi, channelName, attributeId, attributeValue);
#else
  return function_pointers_.GetAttributeViBoolean(vi, channelName, attributeId, attributeValue);
#endif
}

ViStatus NiDMMLibrary::GetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32* attributeValue)
{
  if (!function_pointers_.GetAttributeViInt32) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_GetAttributeViInt32.");
  }
#if defined(_MSC_VER)
  return niDMM_GetAttributeViInt32(vi, channelName, attributeId, attributeValue);
#else
  return function_pointers_.GetAttributeViInt32(vi, channelName, attributeId, attributeValue);
#endif
}

ViStatus NiDMMLibrary::GetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64* attributeValue)
{
  if (!function_pointers_.GetAttributeViReal64) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_GetAttributeViReal64.");
  }
#if defined(_MSC_VER)
  return niDMM_GetAttributeViReal64(vi, channelName, attributeId, attributeValue);
#else
  return function_pointers_.GetAttributeViReal64(vi, channelName, attributeId, attributeValue);
#endif
}

ViStatus NiDMMLibrary::GetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 bufferSize, ViChar attributeValue[])
{
  if (!function_pointers_.GetAttributeViString) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_GetAttributeViString.");
  }
#if defined(_MSC_VER)
  return niDMM_GetAttributeViString(vi, channelName, attributeId, bufferSize, attributeValue);
#else
  return function_pointers_.GetAttributeViString(vi, channelName, attributeId, bufferSize, attributeValue);
#endif
}

ViStatus NiDMMLibrary::GetCalDateAndTime(ViSession vi, ViInt32 calType, ViInt32* month, ViInt32* day, ViInt32* year, ViInt32* hour, ViInt32* minute)
{
  if (!function_pointers_.GetCalDateAndTime) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_GetCalDateAndTime.");
  }
#if defined(_MSC_VER)
  return niDMM_GetCalDateAndTime(vi, calType, month, day, year, hour, minute);
#else
  return function_pointers_.GetCalDateAndTime(vi, calType, month, day, year, hour, minute);
#endif
}

ViStatus NiDMMLibrary::GetDevTemp(ViSession vi, ViString options, ViReal64* temperature)
{
  if (!function_pointers_.GetDevTemp) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_GetDevTemp.");
  }
#if defined(_MSC_VER)
  return niDMM_GetDevTemp(vi, options, temperature);
#else
  return function_pointers_.GetDevTemp(vi, options, temperature);
#endif
}

ViStatus NiDMMLibrary::GetError(ViSession vi, ViStatus* errorCode, ViInt32 bufferSize, ViChar description[])
{
  if (!function_pointers_.GetError) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_GetError.");
  }
#if defined(_MSC_VER)
  return niDMM_GetError(vi, errorCode, bufferSize, description);
#else
  return function_pointers_.GetError(vi, errorCode, bufferSize, description);
#endif
}

ViStatus NiDMMLibrary::GetExtCalRecommendedInterval(ViSession vi, ViInt32* months)
{
  if (!function_pointers_.GetExtCalRecommendedInterval) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_GetExtCalRecommendedInterval.");
  }
#if defined(_MSC_VER)
  return niDMM_GetExtCalRecommendedInterval(vi, months);
#else
  return function_pointers_.GetExtCalRecommendedInterval(vi, months);
#endif
}

ViStatus NiDMMLibrary::GetLastCalTemp(ViSession vi, ViInt32 calType, ViReal64* temperature)
{
  if (!function_pointers_.GetLastCalTemp) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_GetLastCalTemp.");
  }
#if defined(_MSC_VER)
  return niDMM_GetLastCalTemp(vi, calType, temperature);
#else
  return function_pointers_.GetLastCalTemp(vi, calType, temperature);
#endif
}

ViStatus NiDMMLibrary::GetSelfCalSupported(ViSession vi, ViBoolean* selfCalSupported)
{
  if (!function_pointers_.GetSelfCalSupported) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_GetSelfCalSupported.");
  }
#if defined(_MSC_VER)
  return niDMM_GetSelfCalSupported(vi, selfCalSupported);
#else
  return function_pointers_.GetSelfCalSupported(vi, selfCalSupported);
#endif
}

ViStatus NiDMMLibrary::ImportAttributeConfigurationBuffer(ViSession vi, ViInt32 size, ViInt8 configuration[])
{
  if (!function_pointers_.ImportAttributeConfigurationBuffer) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ImportAttributeConfigurationBuffer.");
  }
#if defined(_MSC_VER)
  return niDMM_ImportAttributeConfigurationBuffer(vi, size, configuration);
#else
  return function_pointers_.ImportAttributeConfigurationBuffer(vi, size, configuration);
#endif
}

ViStatus NiDMMLibrary::ImportAttributeConfigurationFile(ViSession vi, ViConstString filePath)
{
  if (!function_pointers_.ImportAttributeConfigurationFile) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ImportAttributeConfigurationFile.");
  }
#if defined(_MSC_VER)
  return niDMM_ImportAttributeConfigurationFile(vi, filePath);
#else
  return function_pointers_.ImportAttributeConfigurationFile(vi, filePath);
#endif
}

ViStatus NiDMMLibrary::InitWithOptions(ViString resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViString optionString, ViSession* vi)
{
  if (!function_pointers_.InitWithOptions) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_InitWithOptions.");
  }
#if defined(_MSC_VER)
  return niDMM_InitWithOptions(resourceName, idQuery, resetDevice, optionString, vi);
#else
  return function_pointers_.InitWithOptions(resourceName, idQuery, resetDevice, optionString, vi);
#endif
}

ViStatus NiDMMLibrary::Initiate(ViSession vi)
{
  if (!function_pointers_.Initiate) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_Initiate.");
  }
#if defined(_MSC_VER)
  return niDMM_Initiate(vi);
#else
  return function_pointers_.Initiate(vi);
#endif
}

ViStatus NiDMMLibrary::LockSession(ViSession vi, ViBoolean* callerHasLock)
{
  if (!function_pointers_.LockSession) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_LockSession.");
  }
#if defined(_MSC_VER)
  return niDMM_LockSession(vi, callerHasLock);
#else
  return function_pointers_.LockSession(vi, callerHasLock);
#endif
}

ViStatus NiDMMLibrary::PerformOpenCableComp(ViSession vi, ViReal64* conductance, ViReal64* susceptance)
{
  if (!function_pointers_.PerformOpenCableComp) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_PerformOpenCableComp.");
  }
#if defined(_MSC_VER)
  return niDMM_PerformOpenCableComp(vi, conductance, susceptance);
#else
  return function_pointers_.PerformOpenCableComp(vi, conductance, susceptance);
#endif
}

ViStatus NiDMMLibrary::PerformShortCableComp(ViSession vi, ViReal64* resistance, ViReal64* reactance)
{
  if (!function_pointers_.PerformShortCableComp) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_PerformShortCableComp.");
  }
#if defined(_MSC_VER)
  return niDMM_PerformShortCableComp(vi, resistance, reactance);
#else
  return function_pointers_.PerformShortCableComp(vi, resistance, reactance);
#endif
}

ViStatus NiDMMLibrary::Read(ViSession vi, ViInt32 maximumTime, ViReal64* reading)
{
  if (!function_pointers_.Read) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_Read.");
  }
#if defined(_MSC_VER)
  return niDMM_Read(vi, maximumTime, reading);
#else
  return function_pointers_.Read(vi, maximumTime, reading);
#endif
}

ViStatus NiDMMLibrary::ReadMultiPoint(ViSession vi, ViInt32 maximumTime, ViInt32 arraySize, ViReal64 readingArray[], ViInt32* actualNumberOfPoints)
{
  if (!function_pointers_.ReadMultiPoint) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ReadMultiPoint.");
  }
#if defined(_MSC_VER)
  return niDMM_ReadMultiPoint(vi, maximumTime, arraySize, readingArray, actualNumberOfPoints);
#else
  return function_pointers_.ReadMultiPoint(vi, maximumTime, arraySize, readingArray, actualNumberOfPoints);
#endif
}

ViStatus NiDMMLibrary::ReadStatus(ViSession vi, ViInt32* acquisitionBacklog, ViInt16* acquisitionStatus)
{
  if (!function_pointers_.ReadStatus) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ReadStatus.");
  }
#if defined(_MSC_VER)
  return niDMM_ReadStatus(vi, acquisitionBacklog, acquisitionStatus);
#else
  return function_pointers_.ReadStatus(vi, acquisitionBacklog, acquisitionStatus);
#endif
}

ViStatus NiDMMLibrary::ReadWaveform(ViSession vi, ViInt32 maximumTime, ViInt32 arraySize, ViReal64 waveformArray[], ViInt32* actualNumberOfPoints)
{
  if (!function_pointers_.ReadWaveform) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ReadWaveform.");
  }
#if defined(_MSC_VER)
  return niDMM_ReadWaveform(vi, maximumTime, arraySize, waveformArray, actualNumberOfPoints);
#else
  return function_pointers_.ReadWaveform(vi, maximumTime, arraySize, waveformArray, actualNumberOfPoints);
#endif
}

ViStatus NiDMMLibrary::ResetWithDefaults(ViSession vi)
{
  if (!function_pointers_.ResetWithDefaults) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_ResetWithDefaults.");
  }
#if defined(_MSC_VER)
  return niDMM_ResetWithDefaults(vi);
#else
  return function_pointers_.ResetWithDefaults(vi);
#endif
}

ViStatus NiDMMLibrary::SelfCal(ViSession vi)
{
  if (!function_pointers_.SelfCal) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_SelfCal.");
  }
#if defined(_MSC_VER)
  return niDMM_SelfCal(vi);
#else
  return function_pointers_.SelfCal(vi);
#endif
}

ViStatus NiDMMLibrary::SendSoftwareTrigger(ViSession vi)
{
  if (!function_pointers_.SendSoftwareTrigger) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_SendSoftwareTrigger.");
  }
#if defined(_MSC_VER)
  return niDMM_SendSoftwareTrigger(vi);
#else
  return function_pointers_.SendSoftwareTrigger(vi);
#endif
}

ViStatus NiDMMLibrary::SetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue)
{
  if (!function_pointers_.SetAttributeViBoolean) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_SetAttributeViBoolean.");
  }
#if defined(_MSC_VER)
  return niDMM_SetAttributeViBoolean(vi, channelName, attributeId, attributeValue);
#else
  return function_pointers_.SetAttributeViBoolean(vi, channelName, attributeId, attributeValue);
#endif
}

ViStatus NiDMMLibrary::SetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue)
{
  if (!function_pointers_.SetAttributeViInt32) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_SetAttributeViInt32.");
  }
#if defined(_MSC_VER)
  return niDMM_SetAttributeViInt32(vi, channelName, attributeId, attributeValue);
#else
  return function_pointers_.SetAttributeViInt32(vi, channelName, attributeId, attributeValue);
#endif
}

ViStatus NiDMMLibrary::SetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue)
{
  if (!function_pointers_.SetAttributeViReal64) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_SetAttributeViReal64.");
  }
#if defined(_MSC_VER)
  return niDMM_SetAttributeViReal64(vi, channelName, attributeId, attributeValue);
#else
  return function_pointers_.SetAttributeViReal64(vi, channelName, attributeId, attributeValue);
#endif
}

ViStatus NiDMMLibrary::SetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViString attributeValue)
{
  if (!function_pointers_.SetAttributeViString) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_SetAttributeViString.");
  }
#if defined(_MSC_VER)
  return niDMM_SetAttributeViString(vi, channelName, attributeId, attributeValue);
#else
  return function_pointers_.SetAttributeViString(vi, channelName, attributeId, attributeValue);
#endif
}

ViStatus NiDMMLibrary::UnlockSession(ViSession vi, ViBoolean* callerHasLock)
{
  if (!function_pointers_.UnlockSession) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_UnlockSession.");
  }
#if defined(_MSC_VER)
  return niDMM_UnlockSession(vi, callerHasLock);
#else
  return function_pointers_.UnlockSession(vi, callerHasLock);
#endif
}

ViStatus NiDMMLibrary::close(ViSession vi)
{
  if (!function_pointers_.close) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_close.");
  }
#if defined(_MSC_VER)
  return niDMM_close(vi);
#else
  return function_pointers_.close(vi);
#endif
}

ViStatus NiDMMLibrary::error_message(ViSession vi, ViStatus errorCode, ViChar errorMessage[256])
{
  if (!function_pointers_.error_message) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_error_message.");
  }
#if defined(_MSC_VER)
  return niDMM_error_message(vi, errorCode, errorMessage);
#else
  return function_pointers_.error_message(vi, errorCode, errorMessage);
#endif
}

ViStatus NiDMMLibrary::reset(ViSession vi)
{
  if (!function_pointers_.reset) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_reset.");
  }
#if defined(_MSC_VER)
  return niDMM_reset(vi);
#else
  return function_pointers_.reset(vi);
#endif
}

ViStatus NiDMMLibrary::self_test(ViSession vi, ViInt16* selfTestResult, ViChar selfTestMessage[256])
{
  if (!function_pointers_.self_test) {
    throw nidevice_grpc::LibraryLoadException("Could not find niDMM_self_test.");
  }
#if defined(_MSC_VER)
  return niDMM_self_test(vi, selfTestResult, selfTestMessage);
#else
  return function_pointers_.self_test(vi, selfTestResult, selfTestMessage);
#endif
}

}  // namespace nidmm_grpc