#pragma once

/**
 * \brief ������������ ���������� �� ������������� �������� ������.
 */
struct Element
{
	/**
	 * \brief ������ true, ���� ���� �������� Data, ����� false.
	 */
	bool IsHaveData;

	/**
	 * \brief ��������.
	 */
	int Data;

	/**
	 * \brief ��������� �� ��������� �������.
	 */
	Element* Next;
};

/**
 * \brief ������������ ���������� �� ������������� ���������� ������.
 */
struct RingBuffer
{
	/**
	 * \brief ������.
	 */
	int Size;

	/**
	 * \brief �������������� �����.
	 */
	int UsedMemory;

	/**
	 * \brief ��������� �����.
	 */
	int FreeMemory;

	/**
	 * \brief �������� �������.
	 */
	Element* Head;

	/**
	 * \brief ��������� ������.
	 */
	Element* IndexOutput;

	/**
	 * \brief ��������� �����.
	 */
	Element* IndexInput;
};

/**
 * \brief ������� ��������� �����.
 * \param buffer �����.
 * \param size ������.
 */
void CreateRingBuffer(RingBuffer* buffer, int size);

/**
 * \brief ���������� �� ���������� �����.
 * \param buffer �����.
 * \return ���������� ���������� ���������� ����� � ������.
 */
int FreeMemoryInfo(RingBuffer* buffer);

/**
 * \brief ���������� �� �������� �����.
 * \param buffer �����.
 * \return ���������� ���������� �������� ����� � ������.
 */
int UsedMemoryInfo(RingBuffer* buffer);

/**
 * \brief ��������� ������� � �����.
 * \param buffer �����.
 * \param data ��������.
 */
void PushElement(RingBuffer* buffer, int data);

/**
 * \brief ����������� ������� �� ������.
 * \param buffer �����.
 * \return ���������� �������� ���������� ��������.
 */
int PopElement(RingBuffer* buffer);

/**
 * \brief ��������� ����� ������ � �����.
 * \param buffer �����.
 */
void AddNewElement(RingBuffer* buffer);

/**
 * \brief ������� �����.
 * \param buffer �����.
 */
void DeleteBuffer(RingBuffer* buffer);
