include $(top_srcdir)/Makefile-shared-lib.inc
all-local : all-blocxx-shared-libs
clean-local : clean-blocxx-shared-libs

include $(top_srcdir)/Makefile-shared-lib-inst.inc
install-exec-local : install-blocxx-shared-libs
uninstall-local : uninstall-blocxx-shared-libs

BLOCXX_SHARED_LIBS = libblocxx.$(LIB_EXT)
SHAREDLIBADD = $(DL_LIB) $(SSL_LIBS) $(REGEX_LIB) $(PCRE_LIB) $(ICONV_LIB)

# increment this number every time a release breaks binary compatibility
LIBRARY_BINARY_VERSION = $(BLOCXX_LIBRARY_VERSION)
MAKEDYLIB=1

# We need to install the real library, not a fake version.
NO_FAKE_LIB_INSTALL=1

blocxxstatlib_LIBRARIES = libblocxx.a

thelibdir = $(libdir)
blocxxstatlibdir = $(thelibdir)

# Shouldn't depend on anything not in common. DON'T ADD ANYTHING TO THIS LIST!
INCLUDES = -I$(top_srcdir)/src -I$(top_builddir)/src

%.cpp: %.re
	re2c -o $@ $<

libblocxx_a_SOURCES = \
AppenderLogger.cpp \
Array.cpp \
Assertion.cpp \
AtomicOps.cpp \
AutoDescriptor.cpp \
BaseStreamBuffer.cpp \
BinarySerialization.cpp \
Bool.cpp \
CerrAppender.cpp \
CerrLogger.cpp \
Char16.cpp \
ClockImpl.cpp \
CmdLineParser.cpp \
Condition.cpp \
COWIntrusiveCountableBase.cpp \
DataStreams.cpp \
DateTime.cpp \
DelayedFormat.cpp \
Demangle.cpp \
DescriptorUtils.cpp \
DescriptorUtils_noexcept.cpp \
DLLSharedLibrary.cpp \
DLLSharedLibraryLoader.cpp \
dlSharedLibrary.cpp \
dlSharedLibraryLoader.cpp \
dyldSharedLibrary.cpp \
dyldSharedLibraryLoader.cpp \
EnumerationException.cpp \
EnvVars.cpp \
Exception.cpp \
Exec.cpp \
PosixExec.cpp \
ExecMockObject.cpp \
FileAppender.cpp \
FileBuf.cpp \
FileInformation.cpp \
FileSystemMockObject.cpp \
Format.cpp \
GenericRWLockImpl.cpp \
GetPass.cpp \
IFileStream.cpp \
IntrusiveCountableBase.cpp \
IOException.cpp \
IOIFC.cpp \
IOIFCStreamBuffer.cpp \
LogAppender.cpp \
LogAppenderScope.cpp \
Logger.cpp \
LoggerImpls.cpp \
LogMessagePatternFormatter.cpp \
MD5.cpp \
MemTracer.cpp \
MTQueue.cpp \
MultiAppender.cpp \
MultiProcessFileAppender.cpp \
Mutex.cpp \
MutexImpl.cpp \
NULLValueException.cpp \
NonRecursiveMutex.cpp \
NonRecursiveMutexImpl.cpp \
NullAppender.cpp \
NullLogger.cpp \
OutOfBoundsException.cpp \
PathSecurity.cpp \
PosixFile.cpp \
PosixFileSystem.cpp \
PosixUnnamedPipe.cpp \
PosixPathSecurity.cpp \
Process.cpp \
RandomNumber.cpp \
ReferenceHelpers.cpp \
Runnable.cpp \
RWLocker.cpp \
SafeCString.cpp \
SafeCStringIO.cpp \
ScopeLogger.cpp \
Secure.cpp \
SecureRand.cpp \
SelectableCallbackIFC.cpp \
SelectableIFC.cpp \
Select.cpp \
SelectEngine.cpp \
ServerSocket.cpp \
ServerSocketImpl.cpp \
SharedLibrary.cpp \
SharedLibraryException.cpp \
SharedLibraryLoader.cpp \
shlSharedLibrary.cpp \
shlSharedLibraryLoader.cpp \
SignalUtils.cpp \
SocketAddress.cpp \
SocketBaseImpl.cpp \
Socket.cpp \
SocketImpl.cpp \
Socket_needs_SSL.cpp \
SocketStreamBuffer.cpp \
SocketUtils.cpp \
SSLCtxMgr.cpp \
SSLException.cpp \
SSLSocketImpl.cpp \
StackTrace.cpp \
StringBuffer.cpp \
String.cpp \
StringConversionImpl.cpp \
StringJoin.cpp \
StringStream.cpp \
SyslogAppender.cpp \
System.cpp \
TempFileEnumerationImplBase.cpp \
TempFileStream.cpp \
ThreadBarrier.cpp \
ThreadCancelledException.cpp \
ThreadCounter.cpp \
Thread.cpp \
ThreadDoneCallback.cpp \
ThreadImpl.cpp \
ThreadOnce.cpp \
ThreadPool.cpp \
ThreadSafeProcess.cpp \
TimeConstants.cpp \
TimeDuration.cpp \
TimeUtils.cpp \
TimePeriod.cpp \
Timeout.cpp \
TimeoutException.cpp \
TimeoutTimer.cpp \
TmUtils.cpp \
UnnamedPipe.cpp \
UserUtils.cpp \
UTF8UtilscompareToIgnoreCase.cpp \
UTF8Utils.cpp \
UUID.cpp \
WaitpidThreadFix.cpp \
Win32SocketBaseImpl.cpp \
RegExException.cpp \
PosixRegEx.cpp \
PerlRegEx.cpp \
IPCMutex.cpp \
IConv.cpp \
LogConfig.cpp


pkginclude_HEADERS = \
AppenderLogger.hpp \
ArrayFwd.hpp \
Array.hpp \
ArrayImpl.hpp \
Assertion.hpp \
AtomicOps.hpp \
AutoDescriptor.hpp \
AutoPtr.hpp \
AutoResource.hpp \
BaseStreamBuffer.hpp \
BinarySerialization.hpp \
Bool.hpp \
ByteSwap.hpp \
CerrAppender.hpp \
CerrLogger.hpp \
Char16.hpp \
Clock.hpp \
ClockImpl.hpp \
CmdLineParser.hpp \
CommonFwd.hpp \
Compare.hpp \
Condition.hpp \
COWIntrusiveCountableBase.hpp \
COWIntrusiveReference.hpp \
COWReferenceBase.hpp \
COWReference.hpp \
Cstr.hpp \
DataStreams.hpp \
DateTime.hpp \
DelayedFormat.hpp \
Demangle.hpp \
DescriptorUtils.hpp \
DescriptorUtils_noexcept.hpp \
DivRem.hpp \
DLLSharedLibrary.hpp \
DLLSharedLibraryLoader.hpp \
dlSharedLibrary.hpp \
dlSharedLibraryLoader.hpp \
dyldSharedLibrary.hpp \
dyldSharedLibraryLoader.hpp \
EnumerationException.hpp \
Enumeration.hpp \
Environ.hpp \
EnvVars.hpp \
Exception.hpp \
ExceptionIds.hpp \
Exec.hpp \
ExecMockObject.hpp \
FileAppender.hpp \
FileBuf.hpp \
File.hpp \
FileInformation.hpp \
FileSystem.hpp \
FileSystemMockObject.hpp \
Format.hpp \
FuncNamePrinter.hpp \
GenericRWLockImpl.hpp \
GetPass.hpp \
GlobalMutex.hpp \
GlobalPtr.hpp \
GlobalString.hpp \
GlobalStringArray.hpp \
HashMap.hpp \
HashMultiMap.hpp \
IFileStream.hpp \
Infinity.hpp \
IntrusiveCountableBase.hpp \
IntrusiveReference.hpp \
IOException.hpp \
IOIFC.hpp \
IOIFCStreamBuffer.hpp \
IstreamBufIterator.hpp \
Join.hpp \
LazyGlobal.hpp \
List.hpp \
LogAppender.hpp \
LogAppenderScope.hpp \
Logger.hpp \
LogLevel.hpp \
LogMessage.hpp \
LogMessagePatternFormatter.hpp \
Map.hpp \
MD5.hpp \
MemoryBarrier.hpp \
MemTracer.hpp \
MTQueue.hpp \
MultiAppender.hpp \
MultiProcessFileAppender.hpp \
Mutex.hpp \
MutexImpl.hpp \
MutexLock.hpp \
NULLValueException.hpp \
NetworkTypes.hpp \
NonRecursiveMutex.hpp \
NonRecursiveMutexImpl.hpp \
NonRecursiveMutexLock.hpp \
NullAppender.hpp \
NullLogger.hpp \
Paths.hpp \
PathSecurity.hpp \
PosixExec.hpp \
PosixUnnamedPipe.hpp \
PosixFileSystem.hpp \
Process.hpp \
RandomNumber.hpp \
RefCountedPimpl.hpp \
RefCount.hpp \
ReferenceBase.hpp \
ReferenceHelpers.hpp \
Reference.hpp \
RefToValue.hpp \
Runnable.hpp \
RWLocker.hpp \
SafeBool.hpp \
SafeCString.hpp \
SafeCStringIO.hpp \
ScopeGuard.hpp \
ScopeLogger.hpp \
Secure.hpp \
SecureRand.hpp \
SelectableCallbackIFC.hpp \
SelectableIFC.hpp \
SelectEngine.hpp \
Select.hpp \
Semaphore.hpp \
ServerSocket.hpp \
ServerSocketImpl.hpp \
SharedLibraryException.hpp \
SharedLibrary.hpp \
SharedLibraryLoader.hpp \
SharedLibraryReference.hpp \
shlSharedLibrary.hpp \
shlSharedLibraryLoader.hpp \
SignalScope.hpp \
SignalUtils.hpp \
SocketAddress.hpp \
SocketBaseImpl.hpp \
SocketException.hpp \
SocketFlags.hpp \
Socket.hpp \
SocketImpl.hpp \
SocketStreamBuffer.hpp \
SocketUtils.hpp \
SortedVectorMap.hpp \
SortedVectorSet.hpp \
SSLCtxMgr.hpp \
SSLException.hpp \
SSLSocketImpl.hpp \
Stack.hpp \
StackTrace.hpp \
StaticAssert.hpp \
StrictWeakOrdering.hpp \
StringBuffer.hpp \
StringEnumeration.hpp \
String.hpp \
StringConversionImpl.hpp \
StringJoin.hpp \
StringStream.hpp \
SyslogAppender.hpp \
System.hpp \
TempFileEnumerationImplBase.hpp \
TempFileStream.hpp \
ThreadBarrier.hpp \
ThreadCancelledException.hpp \
ThreadCounter.hpp \
ThreadDoneCallback.hpp \
Thread.hpp \
ThreadImpl.hpp \
ThreadOnce.hpp \
ThreadPool.hpp \
ThreadSafeProcess.hpp \
ThreadTypes.hpp \
TimeoutException.hpp \
TimeConstants.hpp \
TimeDuration.hpp \
TimePeriod.hpp \
TimeUtils.hpp \
Timeout.hpp \
TimeoutTimer.hpp \
TmUtils.hpp \
Types.hpp \
UnnamedPipe.hpp \
UserUtils.hpp \
UTF8Utils.hpp \
UUID.hpp \
vector.hpp \
WinExec.hpp \
WaitpidThreadFix.hpp \
WaitpidThreadFixFwd.hpp \
RegExException.hpp \
PosixRegEx.hpp \
PerlRegEx.hpp \
RegEx.hpp \
IPCMutex.hpp \
IConv.hpp \
LogConfig.hpp


BUILT_SOURCES = BLOCXX_config.h
DISTCLEANFILES = BLOCXX_config.h
inst_HEADERS = BLOCXX_config.h
instdir = $(pkgincludedir)
