/*
-------------------------------------------------------------------------------
-- Title      : SWcore pseudocode
-- Project    : White Rabbit Switch
-------------------------------------------------------------------------------
-- File       : wrsw_hdl_spec.txt
-- Authors    : Maciej Lipinski (maciej.lipinski@cern.ch)
-- Company    : CERN BE-CO-HT
-- Created    : 2012-01-11
-- Last update: 2012-01-211
-- Description: this is kind-of-pseudo code which attempts to explain how the
--              SWcore and its output queues are working.
--              It does not meant to compile.
-------------------------------------------------------------------------------

*/
#define OUT_QUEUE_NUMBER 8;
#define PORT_NUMBER 8;           //whatever
#define FBM_MEMORY_SIZE  123456; //whatever

typedef struct {
  FIFO    single_prio_fifo; // this is an abstract type of First In First Out 
  boolean empty;            // true if the FIFO is empty
} swcore_out_quque_t;

typedef struct {
  ETHERNET_FRAME  buf;      // here the frame is stored
} swcore_FBM_entry_t;

typedef struct {
  boolean         valid;    // true if the rest of the data is valid
  int             address;  // address of the first page of the frame in the memory
  int             port_mask;// to which ports the frame is to be forwarded (e.g.: 0101 => forward to
			    // ports: 0 and 2,  
  int             priority; // with what priority
  
} swcore_transfer_t;


// here we declare output queues for all the ports and their priorities
swcore_out_quque_t output[PORT_NUMBER][OUT_QUEUE_NUMBER]; 

// the Fabulously Big Memory (FBM)
swcore_FBM_entry_t fbm_memory[FBM_MEMORY_SIZE];

//this is used to transfer frame from input ports to output ports
swcore_transfer_t transfer[PORT_NUMBER];

boolean receive(ETHERNET_FRAME *buf, int port_number)
{
  /*
   * this function receives Ethernet frames from the physical interface of the port_number
   */
}

boolean send(ETHERNET_FRAME *buf, int port_number)
{
  /*
   * this function sends Ethernet frames to the physical interface of the port_number
   */
}

boolean rtu(ETHERNET_FRAME *buf, int *port_mask, int *priority)
{
  /*
   * here, the routing decision is taken
   * the output of this function are:
   * - the decision to which ports the frame should go (port_mask)
   * - the decision what is the priority of the frame
   * - (in the future) it will also tell whether it is broadcast or unicast
   */
}

int mmu()
{
  /*
   * Memory Management Unit - returns the address of the page allocated in the FBM memory 
   */
}

/*
 this function takes data from an ports' input and makes it available to ports' output
 */
void arbiter(int port_mask,int priority,int address, int port_number /*input*/)
{
  transfer[port_number].address    = address;
  transfer[port_number].port_mask  = port_mask;
  transfer[port_number].priority   = priority;
  transfer[port_number].valid      = TRUE;
  
  // here we wait for all the appropriate ports' outputs to read the data
  while (transfer[port_number].port_mask != 0);
  
  transfer[port_number].valid      = FALSE;
  
}

/*
 input block, this is per port
*/
void input_block(int port_number)
{

  ETHERNET_FRAME buf;	//an abstract type to store a received Ethernet frame
  int            port_mask;
  int            priority;
  int            address;
  
  
  while(1)
  {
    if( receive(&buf,port_number) == TRUE )
    {
      // ask Routing Table Unit
      rtu(&buf, &port_mask, &priority);
      
      //acquire address of the first page
      address = mmu();
      
      //store in memory
      fbm_memory[address].buf       = buf;
      
      // forward a pointer to the frame to all the appropriate ports
      // waits until all the appropriate ports read the data
      arbiter(port_mask, priority, address);
    
    }
  
  }

}

void output_block(int port_number)
{
  int address;
  
  /* the below two whiles are done simultaneously (try to imagine :)*/
  
  while(1) 
  {
    for(int i=0; i<PORT_NUMBER; i++)
    {
      if( (transfer[i].port_mask >> port_number) & 0x1 ) // we check all the input ports for a frame
      {                                                  // destined to the port 
	
	int addresss = transfer[i].address;
	int priority = transfer[i].priority;
	
	// put the address of the first page of the frame into the output fifo for a given priority
	output[port_number][priority].single_prio_fifo.push(address);
	output[port_number][priority].empty = FALSE;
	
	// indicate that the frame was received by the output port
	transfer[i].port_mask = transfer[i].port_mask & (0x1 << port_number); 
	
      }
    
    }
  }
  
  // here is the very "advanced" output scheduling algorithm 
  while(1)
  {
    for(int i=OUT_QUEUE_NUMBER-1; i>=0; i--)
    {
      if( output[port_number][i].empty == FALSE)
      {
	// get the pointer to the oldest frame in the output queue
	address = output[port_number][i].single_prio_fifo.front();
	
	// send the frame
	send(fbm_memory[address], port_number);
      }
    }
  }
}


void swcore_main()
{
  int port_number;
  /* 
  * if you imagine that all the below functions are executed simultaneusly, 
  * then you have the idea how the SWCORE works
  */

  // PORT_NUMBER input ports
    input_block(0);
    input_block(1);
    input_block(2);
    input_block(3);
    input_block(4);
    input_block(5);
    input_block(6);
    input_block(7);
  
  // PORT_NUMBER of output ports
  
    input_block(0);
    input_block(1);
    input_block(2);
    input_block(3);
    input_block(4);
    input_block(5);
    input_block(6);
    input_block(7);
  

}