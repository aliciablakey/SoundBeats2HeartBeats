function preload() {
  soundFormats('mp3', 'ogg');
  mySound1 = loadSound('assets/doorbell.mp3');
  mySound2 = loadSound('assets/doorbell.mp3');
  mySound3 = loadSound('assets/doorbell.mp3');
  mySound4 = loadSound('assets/doorbell.mp3');
  mySound5 = loadSound('assets/doorbell.mp3');
  mySound6 = loadSound('assets/doorbell.mp3');

  if(isLoaded(mySound6)){
    console.log("Sound Files Loaded");
  }
}

function setup() {
  mySound.setVolume(0.1);

}