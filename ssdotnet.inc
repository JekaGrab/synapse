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
