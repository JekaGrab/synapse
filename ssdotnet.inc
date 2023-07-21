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
