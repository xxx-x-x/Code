
using System.Net;
using System.Net.Sockets;
using System.Text;

class Program
{
    public static bool isAC = true;
    static List<Socket> clientList = new List<Socket>();
    static Socket server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
     static void Main(string[] args)
    {
        StartServer();
        
    }
     static void StartServer()
    {
        
        try
        {
            IPAddress ip=IPAddress.Parse("0.0.0.0");
            IPEndPoint ipep = new IPEndPoint(ip, 8888);
            server.Bind(ipep);
            server.Listen(1000);
            Console.WriteLine("服务器打开成功！");
            Thread sendThread = new Thread(SendToClient);
            sendThread.Start();
            
        }
        catch (Exception e)
        {
            Console.WriteLine(e);
            throw;
        }
        
    }
     static void SendToClient()
    {
        while (true)
        {
            Socket client = server.Accept();
            Console.WriteLine("已连接上！");
            clientList.Add(client);
            client.Send(Encoding.ASCII.GetBytes("本实验室最牛的服务器！"));
            Thread recevieThread = new Thread(ReceiveSendMsg);
            if (clientList.Count==1)
            {
                recevieThread.Start(clientList[0]);
            }
            
            isAC = false;
            

        }
    }

     static void ReceiveSendMsg(object client)
     {
         Socket Client = client as Socket;
         while (true)
         {
             byte[] buffer = new byte[1024];
             int length = Client.Receive(buffer);
             string msg = Encoding.UTF8.GetString(buffer, 0, length);
             Console.WriteLine("收到"+msg);
         }
     }
    
    
}
