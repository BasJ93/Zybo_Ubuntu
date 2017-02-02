#!/bin/bash
while [[ $# -gt 1 ]]
do
key="$1"

case $key in
	-i|--in)
	IFACEIN="$2"
	shift
	;;
	-o|--out)
	IFACEOUT="$2"
	shift
	;;
	*)
	;;
esac
shift
done

echo CONFIGURING FORWARDING AND MASQUERADING BETWEEN:
echo INTERNAL FACING IFACE	= "${IFACEIN}"
echo EXTERNAL FACING IFACE	= "${IFACEOUT}"

echo 1 > /proc/sys/net/ipv4/ip_forward
iptables -A FORWARD -i $IFACEIN -o $IFACEOUT -j ACCEPT
iptables -A FORWARD -i $IFACEOUT -o $IFACEIN -m state --state ESTABLISHED,RELATED -j ACCEPT
iptables -t nat -A POSTROUTING -o $IFACEOUT -j MASQUERADE
