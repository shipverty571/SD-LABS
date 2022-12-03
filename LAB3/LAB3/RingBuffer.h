#pragma once

struct Element
{
	bool IsHaveData;
	int Data;
	Element* Next;
};

struct RingBuffer
{
	int Size;
	int UsedMemory;
	int FreeMemory;
	Element* Head;
	Element* IndexOutput;
	Element* IndexInput;
};

void CreateRingBuffer(RingBuffer* buffer, int size);
int FreeMemoryInfo(RingBuffer* buffer);
int UsedMemoryInfo(RingBuffer* buffer);
void PushElement(RingBuffer* buffer, int data);
int PopElement(RingBuffer* buffer);
void AddNewElement(RingBuffer* buffer);
void DeleteBuffer(RingBuffer* buffer);
