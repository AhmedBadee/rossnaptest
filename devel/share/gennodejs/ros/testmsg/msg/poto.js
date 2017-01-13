// Auto-generated. Do not edit!

// (in-package testmsg.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------

class poto {
  constructor() {
    this.name = '';
    this.id = 0;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type poto
    // Serialize message field [name]
    bufferInfo = _serializer.string(obj.name, bufferInfo);
    // Serialize message field [id]
    bufferInfo = _serializer.int8(obj.id, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type poto
    let tmp;
    let len;
    let data = new poto();
    // Deserialize message field [name]
    tmp = _deserializer.string(buffer);
    data.name = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [id]
    tmp = _deserializer.int8(buffer);
    data.id = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'testmsg/poto';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f4f347043a64ae4ea786a068b0a9e07c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string name
    int8 id
    
    `;
  }

};

module.exports = poto;
