#pragma once
enum class TajoClientState
{
	NOTCONNECTED,
	CONNECTED,
	SUBSCRIBED,
	CLOSED
};

enum class TajoQueryState
{
	/** successfully submitted */
	SCHEDULED,
	/** Running */
	RUNNING,
	/** Error before a query execution */
	QUERY_ERROR,
	/** Failure after a query launches */
	FAILED,
	/** Killed */
	KILLED,
	/** Wait for completely kill */
	KILLING,
	/** Successfully completed */
	COMPLETED
};
class TajoStatus {
	TajoStatus() : code_(), state_() { }

	~TajoStatus() {  }

	// See https://github.com/apache/tajo/blob/master/tajo-common/src/main/proto/errors.proto
	enum class Code {
		OK = 0,

		WARNING = 100, // Warning

		// General Errors
		INTERNAL_ERROR = 201, // SQLState: XX000 - Error caused by internal bugs (See TajoInternalException)
		NOT_IMPLEMENTED = 202, // SQLState: 0A000 - Not implemented yet, but planned.
		FEATURE_NOT_SUPPORTED = 203, // SQLState: 0A000 - Unsupported feature (usually for unreasonable feature)
		INVALID_RPC_CALL = 204, // SQLState: 08P01 - When invalid RPC call is invoked (e.g., wrong message and absent fields)

		// Query Management and Scheduler
		QUERY_FAILED = 301, // SQLState: 61T01 - Query failed
		QUERY_KILLED = 302, // SQLState: 61T02 - Query killed
		QUERY_TIMEOUT = 303, // SQLState: 61T03 - Timeout for the query
		QUERY_NOT_FOUND = 304, // SQLState: 61T04 - No such query in TajoMaster
		QUERY_NO_DATA = 305, // SQLState: 61T05 - No data due to query fail or error
		INCOMPLETE_QUERY = 306, // SQLState: 61T06 - It occurs when a client requests something of a completed query.

		// Session
		INVALID_SESSION = 401, // SQLState: 62T01 - Session already was invalid
		NO_SUCH_SESSION_VARIABLE = 402, // SQLState: 62T01 - Session variable not found
		INVALID_SESSION_VARIABLE = 403, // SQLState: 62T01 - Session variable is invalid (type mismatch or out of range)

		// Data Exception (SQLState Class - 22)
		DIVISION_BY_ZERO = 451, // SQLState: 22012 - Division by zero
		INVALID_VALUE_FOR_CAST = 452, // SQLState: 22T01 - Invalid data value for cast
		INVALID_URL = 453, // SQLState: 22T02 - Invalid URL

		// Section: Class 42 - Syntax Error or Access Rule Violation
		SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION = 501, // SQLState: 42000
		SYNTAX_ERROR = 502, // SQLState: 42601
		INSUFFICIENT_PRIVILEGE = 503, // SQLState: 42501
		CANNOT_DROP_CURRENT_DATABASE = 504, // SQLState: 42T01

		UNDEFINED_TABLESPACE = 511, // ?
		UNDEFINED_DATABASE = 512, // SQLState: 42T02
		UNDEFINED_SCHEMA = 513, // SQLState:
		UNDEFINED_TABLE = 514, // SQLState: 42P01
		UNDEFINED_COLUMN = 515, // SQLState: 42703
		UNDEFINED_FUNCTION = 516, // SQLState: 42883
		UNDEFINED_INDEX_FOR_TABLE = 517, // ?
		UNDEFINED_INDEX_FOR_COLUMNS = 518, // ?
		UNDEFINED_INDEX_NAME = 519, // ?
		UNDEFINED_PARTITION = 520, // ?
		UNDEFINED_PARTITION_METHOD = 521, // ?
		UNDEFINED_OPERATOR = 522, // SQLState: 42883 (=UNDEFINED_FUNCTION)
		UNDEFINED_PARTITION_KEY = 523, // ?
		UNDEFINED_TABLESPACE_HANDLER = 524, // SQLState: 42T11 - No Tablespace Handler for the URI scheme
		UNDEFINED_PARTITIONS = 525, // ?

		DUPLICATE_TABLESPACE = 531,
		DUPLICATE_DATABASE = 532, // SQLState: 42P04
		DUPLICATE_SCHEMA = 533, // SQLState: 42P06
		DUPLICATE_TABLE = 534, // SQLState: 42P07
		DUPLICATE_COLUMN = 535, // SQLState: 42701
		DUPLICATE_ALIAS = 536, // SQLState: 42712
		DUPLICATE_FUNCTION = 537, // SQLState: 42723
		DUPLICATE_INDEX = 538, // SQLState: 42T07
		DUPLICATE_PARTITION = 539, // SQLState: 42T08

		AMBIGUOUS_TABLE = 541, // SQLState: 42P09
		AMBIGUOUS_COLUMN = 542, // SQLState: 42702,
		AMBIGUOUS_FUNCTION = 543, // SQLState: 42725,
		AMBIGUOUS_PARTITION_DIRECTORY = 544, // ?

		CANNOT_CAST = 601, // SQLState: 42846 - Cast from source type to target type is not supported.
		GROUPING_ERROR = 602, // SQLState: 42803
		WINDOWING_ERROR = 603, // SQLState: 42P20 - PgSQL implementation-defined
		INVALID_RECURSION = 604, // SQLState: 42P19 - PgSQL implementation-defined
		SET_OPERATION_SCHEMA_MISMATCH = 605, // SQLState: 42601 (=SYNTAX_ERROR)
		SET_OPERATION_DATATYPE_MISMATCH = 606, // SQLState: 42601 (=SYNTAX_ERROR)
		INVALID_FOREIGN_KEY = 621, // SQLState: 42830
		INVALID_NAME = 622, // SQLState: 42602
		INVALID_COLUMN_DEFINITION = 623, // SQLState: 42611
		NAME_TOO_LONG = 624, // SQLState: 42622
		RESERVED_NAME = 625, // SQLState: 42939
		DATATYPE_MISMATCH = 626, // SQLState: 42804
		INDETERMINATE_DATATYPE = 627, // SQLState: 42P18 - PgSQL implementation -defined



		// Expressions
		INVALID_EXPRESSION = 701,
		INVALID_DATATYPE = 703,

		NUMERIC_OVERFLOW = 803,  // Numeric value overflow
		VALUE_LARGER_THAN_PRECISION = 804,  // Value larger than column precision

		// Meta Catalog
		CAT_UPGRADE_REQUIRED = 901,  // Migration
		CAT_CANNOT_CONNECT = 902,  // Cannot connect metadata server

		// Catalog store
		CAT_UNSUPPORTED_CATALOG_STORE = 905, // Unsupported type of catalog store

		// Linked Metadata (LMD)
		LMD_NO_MATCHED_DATATYPE = 910,  // No matched data type between Tajo and connector

		// Storage and Data Format
		UNAVAILABLE_TABLE_LOCATION = 1001, // SQLState: ? - Unavailable table location
		UNKNOWN_DATAFORMAT = 1002, // SQLState: ? - Unknown Data Format
		UNSUPPORTED_DATATYPE = 1003, // SQLState: ? - Unsupported data type
		INVALID_TABLE_PROPERTY = 1004, // SQLState: ? - Invalid Table Property
		MISSING_TABLE_PROPERTY = 1005, // SQLState: ? - Missing table property

		// Client Connection
		CLIENT_CONNECTION_EXCEPTION = 1101, // SQLState: 08000 - Client connection error
		CLIENT_CONNECTION_DOES_NOT_EXIST = 1103, // SQLState: 08003 - Client connection has been closed.
		CLIENT_UNABLE_TO_ESTABLISH_CONNECTION = 1102, // SQLState: 08006 - Client connection failure
		CLIENT_PROTOCOL_PROTOCOL_VIOLATION = 1104, // SQLState: 08P01 - Protocol violation

		// 53 - Invalid Operand or Inconsistent Specification
		INSUFFICIENT_RESOURCE = 53000,
		DISK_FULL = 53100,
		OUT_OF_MEMORY = 53200,

		// 54 - SQL or Product Limit Exceeded
		PROGRAM_LIMIT_EXCEEDED = 54000,
		STATEMENT_TOO_COMPLEX = 54001,
		STRING_CONSTANT_TOOL_LONG = 54002,
		TOO_LARGE_INPUT_FOR_CROSS_JOIN = 54003,
		INVALID_INPUTS_FOR_CROSS_JOIN = 54004,

		TOO_MANY_TABLES = 54006,
		TOO_MANY_COLUMNS = 54011,
		TOO_MANY_ARGUMENTS = 54023,

		// 55 - Object Not in Prerequisite State
		// 56 - Miscellaneous SQL or Product Error
		// 57 - Resource Not Available or Operator Intervention

		// 58 - System Error
		IO_ERROR = 58030,


		// underlying system errors based on errno.h.
		TAJO_EPERM = 10001,  // Operation not permitted
		TAJO_ENOENT = 10002,  // No such file or directory
		TAJO_ESRCH = 10003,  // No such process
		TAJO_EINTR = 10004,  // Interrupted system call
		TAJO_EIO = 10005,  // I/O error
		TAJO_ENXIO = 10006,  // No such device or address
		TAJO_E2BIG = 10007,  // Argument list too long
		TAJO_ENOEXEC = 10008,  // Exec format error
		TAJO_EBADF = 10009,  // Bad file number
		TAJO_ECHILD = 10010,  // No child processes
		TAJO_EAGAIN = 10011,  // Try again
		TAJO_ENOMEM = 10012,  // Out of memory
		TAJO_EACCES = 10013,  // Permission denied
		TAJO_EFAULT = 10014,  // Bad address
		TAJO_ENOTBLK = 10015,  // Block device required
		TAJO_EBUSY = 10016,  // Device or resource busy
		TAJO_EEXIST = 10017,  // File exists
		TAJO_EXDEV = 10018,  // Cross-device link
		TAJO_ENODEV = 10019,  // No such device
		TAJO_ENOTDIR = 10020,  // Not a directory
		TAJO_EISDIR = 10021,  // Is a directory
		TAJO_EINVAL = 10022,  // Invalid argument
		TAJO_ENFILE = 10023,  // File table overflow
		TAJO_EMFILE = 10024,  // Too many open files
		TAJO_ENOTTY = 10025,  // Not a typewriter
		TAJO_ETXTBSY = 10026,  // Text file busy
		TAJO_EFBIG = 10027,  // File too large
		TAJO_ENOSPC = 10028,  // No space left on device
		TAJO_ESPIPE = 10029,  // Illegal seek
		TAJO_EROFS = 10030,  // Read-only file system
		TAJO_EMLINK = 10031,  // Too many links
		TAJO_EPIPE = 10032,  // Broken pipe
		TAJO_EDOM = 10033,  // Math argument out of domain of func
		TAJO_ERANGE = 10034,  // Math result not representable

		TAJO_EDEADLK = 10035,  // Resource deadlock would occur
		TAJO_ENAMETOOLONG = 10036,  // File name too long
		TAJO_ENOLCK = 10037,  // No record locks available
		TAJO_ENOSYS = 10038,  // Function not implemented
		TAJO_ENOTEMPTY = 10039,  // Directory not empty
		TAJO_ELOOP = 10040,  // Too many symbolic links encountered
		TAJO_EWOULDBLOCK                = EAGAIN,  // Operation would block
		TAJO_ENOMSG = 10042,  // No message of desired type
		TAJO_EIDRM = 10043,  // Identifier removed
		TAJO_ECHRNG = 10044,  // Channel number out of range
		TAJO_EL2NSYNC = 10045,  // Level 2 not synchronized
		TAJO_EL3HLT = 10046,  // Level 3 halted
		TAJO_EL3RST = 10047,  // Level 3 reset
		TAJO_ELNRNG = 10048,  // Link number out of range
		TAJO_EUNATCH = 10049,  // Protocol driver not attached
		TAJO_ENOCSI = 10050,  // No CSI structure available
		TAJO_EL2HLT = 10051,  // Level 2 halted
		TAJO_EBADE = 10052,  // Invalid exchange
		TAJO_EBADR = 10053,  // Invalid request descriptor
		TAJO_EXFULL = 10054,  // Exchange full
		TAJO_ENOANO = 10055,  // No anode
		TAJO_EBADRQC = 10056,  // Invalid request code
		TAJO_EBADSLT = 10057,  // Invalid slot
		TAJO_EDEADLOCK                  = EDEADLK,
		TAJO_EBFONT = 10059,  // Bad font file format
		TAJO_ENOSTR = 10060,  // Device not a stream
		TAJO_ENODATA = 10061,  // No data available
		TAJO_ETIME = 10062,  // Timer expired
		TAJO_ENOSR = 10063,  // Out of streams resources
		TAJO_ENONET = 10064,  // Machine is not on the network
		TAJO_ENOPKG = 10065,  // Package not installed
		TAJO_EREMOTE = 10066,  // Object is remote
		TAJO_ENOLINK = 10067,  // Link has been severed
		TAJO_EADV = 10068,  // Advertise error
		TAJO_ESRMNT = 10069,  // Srmount error
		TAJO_ECOMM = 10070,  // Communication error on send
		TAJO_EPROTO = 10071,  // Protocol error
		TAJO_EMULTIHOP = 10072,  // Multihop attempted
		TAJO_EDOTDOT = 10073,  // RFS specific error
		TAJO_EBADMSG = 10074,  // Not a data message
		TAJO_EOVERFLOW = 10075,  // Value too large for defined data type
		TAJO_ENOTUNIQ = 10076,  // Name not unique on network
		TAJO_EBADFD = 10077,  // File descriptor in bad state
		TAJO_EREMCHG = 10078,  // Remote address changed
		TAJO_ELIBACC = 10079,  // Can not access a needed shared library
		TAJO_ELIBBAD = 10080,  // Accessing a corrupted shared library
		TAJO_ELIBSCN = 10081,  // .lib section in a.out corrupted
		TAJO_ELIBMAX = 10082,  // Attempting to link in too many shared libraries
		TAJO_ELIBEXEC = 10083,  // Cannot exec a shared library directly
		TAJO_EILSEQ = 10084,  // Illegal byte sequence
		TAJO_ERESTART = 10085,  // Interrupted system call should be restarted
		TAJO_ESTRPIPE = 10086,  // Streams pipe error
		TAJO_EUSERS = 10087,  // Too many users
		TAJO_ENOTSOCK = 10088,  // Socket operation on non-socket
		TAJO_EDESTADDRREQ = 10089,  // Destination address required
		TAJO_EMSGSIZE = 10090,  // Message too long
		TAJO_EPROTOTYPE = 10091,  // Protocol wrong type for socket
		TAJO_ENOPROTOOPT = 10092,  // Protocol not available
		TAJO_EPROTONOSUPPORT = 10093,  // Protocol not supported
		TAJO_ESOCKTNOSUPPORT = 10094,  // Socket type not supported
		TAJO_EOPNOTSUPP = 10095,  // Operation not supported on transport endpoint
		TAJO_EPFNOSUPPORT = 10096,  // Protocol family not supported
		TAJO_EAFNOSUPPORT = 10097,  // Address family not supported by protocol
		TAJO_EADDRINUSE = 10098,  // Address already in use
		TAJO_EADDRNOTAVAIL = 10099,  // Cannot assign requested address
		TAJO_ENETDOWN = 10100, // Network is down
		TAJO_ENETUNREACH = 10101, // Network is unreachable
		TAJO_ENETRESET = 10102, // Network dropped connection because of reset
		TAJO_ECONNABORTED = 10103, // Software caused connection abort
		TAJO_ECONNRESET = 10104, // Connection reset by peer
		TAJO_ENOBUFS = 10105, // No buffer space available
		TAJO_EISCONN = 10106, // Transport endpoint is already connected
		TAJO_ENOTCONN = 10107, // Transport endpoint is not connected
		TAJO_ESHUTDOWN = 10108, // Cannot send after transport endpoint shutdown
		TAJO_ETOOMANYREFS = 10109, // Too many references: cannot splice
		TAJO_ETIMEDOUT = 10110, // Connection timed out
		TAJO_ECONNREFUSED = 10111, // Connection refused
		TAJO_EHOSTDOWN = 10112, // Host is down
		TAJO_EHOSTUNREACH = 10113, // No route to host
		TAJO_EALREADY = 10114, // Operation already in progress
		TAJO_EINPROGRESS = 10115, // Operation now in progress
		TAJO_ESTALE = 10116, // Stale NFS file handle
		TAJO_EUCLEAN = 10117, // Structure needs cleaning
		TAJO_ENOTNAM = 10118, // Not a XENIX named type file
		TAJO_ENAVAIL = 10119, // No XENIX semaphores available
		TAJO_EISNAM = 10120, // Is a named type file
		TAJO_EREMOTEIO = 10121, // Remote I/O error
		TAJO_EDQUOT = 10122, // Quota exceeded
		TAJO_ENOMEDIUM = 10123, // No medium found
		TAJO_EMEDIUMTYPE = 10124, // Wrong medium type
		TAJO_ECANCELED = 10125, // Operation Canceled
		TAJO_ENOKEY = 10126, // Required key not available
		TAJO_EKEYEXPIRED = 10127, // Key has expired
		TAJO_EKEYREVOKED = 10128, // Key has been revoked
		TAJO_EKEYREJECTED = 10129, // Key was rejected by service

		// for robust mutexes
		TAJO_EOWNERDEAD = 10130, // Owner died
		TAJO_ENOTRECOVERABLE = 10131 // State not recoverable
	};

	// Returns true if the status indicates success.
	bool ok() const { return (state_.empty()); }

private:
	Code code_; // state code
	std::string state_; // error message
};