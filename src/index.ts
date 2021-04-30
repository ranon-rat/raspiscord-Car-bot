import { StillCamera } from "pi-camera-connect";
import * as johnny from "johnny-five";
import { Client } from "discord.js";
import * as fs from "fs";
// constants
import { token } from "./settings.json";
// classes
const raspi = require("raspi-io").RaspiIO;
const stillCamera: StillCamera = new StillCamera();
const board: johnny.Board = new johnny.Board({
  io: new raspi(),
});
const client: Client = new Client();

// Take still image and save to disk
const takePhoto: ()=>void =  () => {
  const image =  stillCamera.takeImage();
  fs.writeFileSync("request.jpg", image);
};
board.pinMode("P1-7", 1)
board.pinMode("P1-8",1)
client.on("ready", () => console.log("starting bot"));
client.on("message", async (msg) => {
  if (msg.content === "!photo") {
    takePhoto();
    msg.channel.send({
      files: ["./request.jpg"],
    });
  }
  if (msg.content === "!left") {
    console.log(`left ${msg.author.username}`);

    setTimeout(() => board.digitalWrite("P1-7", 1) , 1000);
    board.digitalWrite("P1-7", 0)
  }
  if(msg.content==="!right"){
   
    setTimeout(() => board.digitalWrite("P1-8", 1) , 1000);
    board.digitalWrite("P1-8",0)
  }
});
client.login(token);
