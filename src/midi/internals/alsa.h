#ifndef MIDI_INTERNAL_ALSA_H
#define MIDI_INTERNAL_ALSA_H
#ifdef __linux__

#include <stdint.h>

typedef int32_t MIDIObjectRef;
typedef MIDIObjectRef MIDIEndpointRef;

typedef struct Device {
  char *name;
  MIDIEndpointRef endpoint;
} Device;

typedef struct Devices {
  Device **store;
  int count;
} Devices;

typedef int64_t MIDITimestamp;

typedef struct MidiPacket {
  MIDITimestamp timestamp;
  int16_t length;
  int32_t *data[];
} MidiPacket;

typedef struct MIDINotification {
  int32_t messageID;
  int32_t messageSize;
} MIDINotification;

typedef struct MIDIPacketList {
  int32_t numPackets;
  MidiPacket packet;
} MIDIPacketList;

Devices *MMAlsa_GetDevices();
Device *MMAlsa_CreateVirtualDevice(char *name);

#endif
#endif