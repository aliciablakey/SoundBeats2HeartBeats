//example from cc18

// server variables
var dataServer;
var pubKey = 'pub-c-6a70c208-687c-46db-9240-9716ff3515bc';
var subKey = 'sub-c-ca11013c-ec6a-11e8-a895-42b57d7e7824';
var channelName = "audio";
 

//OCAD KEYSET
//var pubKey = 'pub-c-6a70c208-687c-46db-9240-9716ff3515bc';
//var subKey = 'sub-c-ca11013c-ec6a-11e8-a895-42b57d7e7824';
//var channelName = "clicks";

var turntable;


function setup() 
{
    createCanvas(1920,1080);
    turntable = createVideo('Media/turntable.mp4');
    turntable.hide(); 
    
}

function draw() 
{
image(turntable,10,10); // draw the video frame to canvas
}