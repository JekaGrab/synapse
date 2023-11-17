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
  FIOASYNC     = integer($8004667d);

  SOMAXCONN       = integer($7fffffff);

  IPPROTO_IP = ProtocolType.IP;
  IPPROTO_ICMP = ProtocolType.Icmp;
  IPPROTO_IGMP = ProtocolType.Igmp;
  IPPROTO_TCP = ProtocolType.Tcp;
  IPPROTO_UDP = ProtocolType.Udp;
  IPPROTO_RAW = ProtocolType.Raw;
  IPPROTO_IPV6 = ProtocolType.IPV6;
//
  IPPROTO_ICMPV6 = ProtocolType.Icmp; //??

  SOCK_STREAM     = SocketType.Stream;
  SOCK_DGRAM      = SocketType.Dgram;
  SOCK_RAW        = SocketType.Raw;
  SOCK_RDM        = SocketType.Rdm;
  SOCK_SEQPACKET  = SocketType.Seqpacket;

  SOL_SOCKET = SocketOptionLevel.Socket;
  SOL_IP = SocketOptionLevel.Ip;


  IP_OPTIONS          = SocketOptionName.IPOptions;
  IP_HDRINCL          = SocketOptionName.HeaderIncluded;
  IP_TOS              = SocketOptionName.TypeOfService;           { set/get IP Type Of Service       }
  IP_TTL              = SocketOptionName.IpTimeToLive;           { set/get IP Time To Live          }
  IP_MULTICAST_IF     = SocketOptionName.MulticastInterface;           { set/get IP multicast interface   }
  IP_MULTICAST_TTL    = SocketOptionName.MulticastTimeToLive;           { set/get IP multicast timetolive  }
  IP_MULTICAST_LOOP   = SocketOptionName.MulticastLoopback;           { set/get IP multicast loopback    }
  IP_ADD_MEMBERSHIP   = SocketOptionName.AddMembership;           { add  an IP group membership      }
  IP_DROP_MEMBERSHIP  = SocketOptionName.DropMembership;           { drop an IP group membership      }
  IP_DONTFRAGMENT     = SocketOptionName.DontFragment;           { set/get IP Don't Fragment flag   }

  IPV6_UNICAST_HOPS      = 8;  // TTL
  IPV6_MULTICAST_IF      = 9;  // set/get IP multicast i/f
  IPV6_MULTICAST_HOPS    = 10; // set/get IP multicast ttl
  IPV6_MULTICAST_LOOP    = 11; // set/get IP multicast loopback
  IPV6_JOIN_GROUP        = 12; // add an IP group membership
  IPV6_LEAVE_GROUP       = 13; // drop an IP group membership

  SO_DEBUG        = SocketOptionName.Debug;          { turn on debugging info recording }
  SO_ACCEPTCONN   = SocketOptionName.AcceptConnection;          { socket has had listen() }
  SO_REUSEADDR    = SocketOptionName.ReuseAddress;          { allow local address reuse }
  SO_KEEPALIVE    = SocketOptionName.KeepAlive;          { keep connections alive }
  SO_DONTROUTE    = SocketOptionName.DontRoute;          { just use interface addresses }
  SO_BROADCAST    = SocketOptionName.Broadcast;          { permit sending of broadcast msgs }
  SO_USELOOPBACK  = SocketOptionName.UseLoopback;          { bypass hardware when possible }
  SO_LINGER       = SocketOptionName.Linger;          { linger on close if data present }
  SO_OOBINLINE    = SocketOptionName.OutOfBandInline;          { leave received OOB data in line }
  SO_DONTLINGER   = SocketOptionName.DontLinger;
{ Additional options. }
  SO_SNDBUF       = SocketOptionName.SendBuffer;          { send buffer size }
  SO_RCVBUF       = SocketOptionName.ReceiveBuffer;          { receive buffer size }
  SO_SNDLOWAT     = SocketOptionName.SendLowWater;          { send low-water mark }
  SO_RCVLOWAT     = SocketOptionName.ReceiveLowWater;          { receive low-water mark }
  SO_SNDTIMEO     = SocketOptionName.SendTimeout;          { send timeout }
  SO_RCVTIMEO     = SocketOptionName.ReceiveTimeout;          { receive timeout }
  SO_ERROR        = SocketOptionName.Error;          { get error status and clear }
  SO_TYPE         = SocketOptionName.Type;          { get socket type }

{ WinSock 2 extension -- new options }
//  SO_GROUP_ID       = $2001; { ID of a socket group}
//  SO_GROUP_PRIORITY = $2002; { the relative priority within a group}
//  SO_MAX_MSG_SIZE   = $2003; { maximum message size }
//  SO_PROTOCOL_INFOA = $2004; { WSAPROTOCOL_INFOA structure }
//  SO_PROTOCOL_INFOW = $2005; { WSAPROTOCOL_INFOW structure }
//  SO_PROTOCOL_INFO  = SO_PROTOCOL_INFOA;
//  PVD_CONFIG        = $3001; {configuration info for service provider }
{ Option for opening sockets for synchronous access. }
//  SO_OPENTYPE     = $7008;
//  SO_SYNCHRONOUS_ALERT    = $10;
//  SO_SYNCHRONOUS_NONALERT = $20;
{ Other NT-specific options. }
//  SO_MAXDG        = $7009;
//  SO_MAXPATHDG    = $700A;
//  SO_UPDATE_ACCEPT_CONTEXT     = $700B;
//  SO_CONNECT_TIME = $700C;


  { All Windows Sockets error constants are biased by WSABASEERR from the "normal" }
  WSABASEERR              = 10000;

{ Windows Sockets definitions of regular Microsoft C error constants }

  WSAEINTR                = (WSABASEERR+4);
