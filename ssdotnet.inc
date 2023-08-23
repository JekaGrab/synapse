interface

uses
  SyncObjs, SysUtils, Classes,
  System.Net,
  System.Net.Sockets;

const
  DLLStackName = '';
  WinsockLevel = $0202;

function InitSocketInterface(stack: string): Boolean;

type
  u_char = Char;
  u_short = Word;
  u_int = Integer;
  ULong = cardinal;
  TMemory = Array of byte;
TLinger = LingerOption;
  TSocket = socket;
  TAddrFamily = AddressFamily;

const
  WSADESCRIPTION_LEN     =   256;
  WSASYS_STATUS_LEN      =   128;
type
  PWSAData = ^TWSAData;
  TWSAData = packed record
    wVersion: Word;
    wHighVersion: Word;
    szDescription: array[0..WSADESCRIPTION_LEN] of Char;
    szSystemStatus: array[0..WSASYS_STATUS_LEN] of Char;
    iMaxSockets: Word;
    iMaxUdpDg: Word;
//    lpVendorInfo: PChar;
  end;

const
  MSG_NOSIGNAL = 0;
  INVALID_SOCKET = nil;
  AF_UNSPEC = AddressFamily.Unspecified;
  AF_INET = AddressFamily.InterNetwork;
  AF_INET6 = AddressFamily.InterNetworkV6;
  SOCKET_ERROR = integer(-1);

  FIONREAD     = integer($4004667f);
  FIONBIO      = integer($8004667e);
