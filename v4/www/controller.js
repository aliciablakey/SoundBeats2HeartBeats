var dataServer;
var pubKey = 'pub-c-3d324972-7fe6-4f36-b052-bfdd0e3f9c27';
var subKey = 'sub-c-0eb9c374-e931-11e8-b652-8a5de3112bb9';
var channelName = "clicks";

//BUTTONS
var buttons = [];   //array that will hold the objects
var totRx = 2;     //how many to create in X direction of the grid
var totRy = 3;     //how many to create in Y direction of the grid
var border = 80;    //pixel boarder around the grid
var maxRadius;      //sets the max size of each circle based on the size of the window
var showCount = true;

function setup() {
  createCanvas(400,600);

  dataServer = new PubNub(
    {
      publish_key   : pubKey,  //get these from the pubnub account online
      subscribe_key : subKey,  
      ssl: true  //enables a secure connection. This option has to be used if using the OCAD webspace
    });
  
  //attach callbacks to the pubnub object to handle messages and connections
  dataServer.addListener({ message: readIncoming, presence: whoisconnected })
  dataServer.subscribe({channels: [channelName]});

  maxRadius = (width-border)/(totRx*2); //calculate the max size of the circles based on the window size
  
  //create a grid of circles using the PlayButton class *see below for class
  for (var rx = 0; rx<totRx; rx++)
  {
    for (var ry = 0; ry<totRy; ry++)
    {
      buttons.push(new PlayButton(map(rx,0,totRx,border,width-border),map(ry,0,totRy,border,height),5,maxRadius));
    }

  }

}

function draw() 
{

background(255);

  //cycle through the buttons array that holds all of the objects to perform the calculations on each one.
  for (var i = 0;i<buttons.length;i++)
  {
    buttons[i].display();  //this calls the display function inside each object
  }

}



//This is the PlayButton class created that defines each of the circles and their movement
function PlayButton(x,y,minSize,maxSize)
{

  //these are the local variables for the class 
  this.x = x;
  this.y = y;
  this.minSize = minSize;
  this.maxSize = maxSize+10;
  this.clicked = 0;
  this.speed = 0.001;
  this.randStart = random(0,1000);
  this.maxClicks = 1;

  ///this is the function that is called in draw to perform calculations on each and draw the circles
  this.display = function() {
    fill(0,255,0,map(this.clicked,0,this.maxClicks,0,100))  //increases opacity with more clicks
    stroke(0);
    strokeWeight(0.2);

    //this draws the actual circle
    ellipse(this.x, this.y, 100,100);

 
  if(this.clicked ==1)  //if it has been clicked on show how many times
  {
    fill(100);
    noStroke();
    textSize(12);
    textAlign(CENTER,CENTER);
    // text(this.clicked,this.x,this.y);
  } else if (this.clicked > 1) {
    fill(100)
    noStroke();
    textAlign(CENTER,CENTER)
    this.clicked = 0;
  }
      
  }



  //checks if clicked on; if yes, flips the this.clicked
  this.hitCheck = function(mx, my, index)
  {
    if(dist(this.x,this.y,mx,my)<(maxRadius-1)) //click within circle
    {

      for (i = 0; i <= buttons.length-1; i++){
       if(i == index) {
         buttons[i].clicked = buttons[i].clicked + 1;
         playerSwitch(playswitch = this.clicked)
        
         playSound(i);
       } else {
         buttons[i].clicked = 0;
       }
      }

    }
  }

  function playerSwitch(playswitch){
    console.log("this.clicked", playswitch)
    switch(this.clicked){
        case "0": {
          playerStop(); console.log("play stopped")
        } 
        case "1": {player();}
    } 
  }



}

///uses built in mouseClicked function to send the data to the pubnub server
function mouseClicked() {
 
  // Send Data to the server to draw it in all other canvases
  dataServer.publish(
    {
      channel: channelName,
      message: 
      {       //set the message objects property name and value combos    
        x: mouseX,
        y: mouseY 
      }
    });

}

function readIncoming(inMessage) //when new data comes in it triggers this function, 
{                               // this works becsuse we subscribed to the channel in setup()
   console.log(inMessage);
  if(inMessage.channel == channelName)
  {
    var clickX = inMessage.message.x;
    var clickY = inMessage.message.y;
    for (var i = 0;i<buttons.length;i++)
    {
    buttons[i].hitCheck(clickX,clickY, i);  //feed the x y coordinates of all clicks in messages to objects
  }
  }
}

function whoisconnected(connectionInfo)
{

}