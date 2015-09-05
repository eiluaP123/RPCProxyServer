HOW  TO RUN THE CODE

*** To avoid any confusion, and maintain modularity we created separate folders for each cache policy with each workload. ***

======================================================================================================================================================
(1) Each folder has the executables created and compiled. Those can be directly run as :

./server.o FOR SERVER
./Something_client* FOR THE APPROPRIATE CLIENT (* implies the name of the client file generated in each folder. It will be auto-recognized with tab)

=======================================================================================================================================================
(2) Each folder has all the object files necessary to compile the server and client codes. 
There is a Makefile in each folder to make the server and client executables for that particular cache and workload.

COMMANDS

After running the ‘make’ command inside each folder.
./server.o will start the server on the machine.
./Something_client_* will run the client code. (* is for different naming used in each folder)

======================================================================================================================================================
(3) ANOTHER WAY TO COMPILE AND RUN CODE. INDIVIDUALLY COMPILE FILES IN EACH FOLDER.
THE SERVER HAS TO BE COMPILED WITH THE RESPECTIVE CACHE POLICY (SEPARATE FOR EACH FOLDER).
THE CLIENT FILE HAS DIFFERENT NAMES IN DIFFERENT FOLDERS.

GO TO THE FOLDER
E.G. LRU_uniform_workload

//TO COMPILE SERVER
g++ -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -Wall -I/usr/local/include/thrift Something_server.cpp Something.cpp test_constants.cpp test_types.cpp LRU.cpp -L/usr/local/lib -lthrift -L/usr/lib/x86_64-linux-gnu -lcurl -fpermissive -w -o server.o

//TO RUN SERVER
./server.o

//TO COMPILE CLIENT
g++ -std=c++11 -Wall -I/usr/local/include/thrift -c Something_client_uniform.cpp -o client_uniform.o 

//TO LINK CLIENT
g++ -L/usr/local/lib client_uniform.o something.o constants.o types.o -o Something_client_uniform -lthrift

//TO RUN CLIENT
./Something_client_uniform

======================================================================================================================================================


