var sounds = [];
function preload() {
  soundFormats('mp3', 'ogg');
  if(env != "mobile") {
    mySound1 = loadSound('assets/media/audio/elsueno.mp3');
    mySound2 = loadSound('assets/media/audio/hiphop.mp3');
    mySound3 = loadSound('assets/media/audio/rockangel.mp3');
    mySound4 = loadSound('assets/media/audio/summer.mp3');
    mySound5 = loadSound('assets/media/audio/summer.mp3');
    mySound6 = loadSound('assets/media/audio/summer.mp3');  
    sounds.push(mySound1);
    sounds.push(mySound2);
    sounds.push(mySound3);
    sounds.push(mySound4);
    sounds.push(mySound5);
    sounds.push(mySound6);
  }

  
  console.log(env);
}


var startTime = 0;
var rate = 1;
var amp = .5;

function playSound(soundToPlay){
  if(env == "mobile") return;
  play_it = true;
  // play([startTime], [rate], [amp], [cueStart], [duration])
 if(sounds[soundToPlay].isPlaying()){
    play_it = false;
 }
  sounds.forEach(function(s){
    s.stop();
  })

  if(play_it) {
    sounds[soundToPlay].play(startTime, rate, amp);
    document.getElementById("BackgroundVideo").play();

  } else {
    document.getElementById("BackgroundVideo").pause();
  }
  return "play clicked";
}

function playerStop(){
  sounds.forEach(function(s){
    s.stop();
  })
  return "stopped";
}