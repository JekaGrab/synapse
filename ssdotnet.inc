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
