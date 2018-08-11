#include "State.h"

using namespace std;

int main()
{
	TCPState* tcpstat = new TCPClose();
	TCPConn* tcpCon = new TCPConn(tcpstat);
	tcpCon->Request();
	tcpCon->Request();
	tcpCon->Request();
	tcpCon->Request();
	tcpCon->Request();
	tcpCon->Request();
	tcpCon->Request();
	tcpCon->Request();
	return 0;
}