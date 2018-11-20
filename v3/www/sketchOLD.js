//example from cc18
//*****************************************************************************
// FOR MOBILE USE ONLY; FOR MOBILE USE ONLY
//*****************************************************************************

// step one: play video


// server variables
var dataServer;
var pubKey = 'pub-c-6a70c208-687c-46db-9240-9716ff3515bc';
var subKey = 'sub-c-ca11013c-ec6a-11e8-a895-42b57d7e7824';
var channelName = "audio";
 


function setup() 
{

  createCanvas(600,1200);
  

   // initialize pubnub
  dataServer = new PubNub(
  {
    publish_key   : pubKey,  //get these from the pubnub account online
    subscribe_key : subKey,  
    ssl: false  //enables a secure connection. This option has to be used if using the OCAD webspace
  });
  
//  //attach callbacks to the pubnub object to handle messages and connections
//  dataServer.addListener({ message: readIncoming, presence: whoisconnected })
//  dataServer.subscribe({channels: [channelName]});


}

function draw() 
{
    
}