*** INSTRUCTIONS TO COMPILE & RUN ***

TO RUN:

1. Open terminal (Ctrl+Alt+T)
2. Open folder location eg.
	cd home/Documents/trirpc

3. Run trirpc server
	./trirpc_server
4. Open new terminal
5. Open folder location (same as step 2)
6. Run client program
	./trirpc_client localhost  (Speciefies what host the server is running on)
		
TO COMPILE:
1. Make a copy of all files in a separate folder.
2. Open copy directory and delete all files except trirpc.x
2. Open terminal (Ctrl+Alt+T)
3. Open folder location (where trirpc.x is) eg.
	cd home/Documents/trirpc
4. Run:
	rpcgen -a -C trirpc.x
5. Copy and paste content of original trirpc_server.c with that of the generated  trirpc_server.c 
6. Copy and paste content of original trirpc_client.c with that of the generated  trirpc_client.c 
7.Run:
	make -f Makefile.trirpc 
8. Follow instuctions above to run.
