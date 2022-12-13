#pragma once

/**
 * \brief ������������ ���������� �� ������������� �����.
 */
struct Stack
{
	/**
	 * \brief �����.
	 */
	int* Buffer;

	/**
	 * \brief ������� ������� �����.
	 */
	int Top;

	/**
	 * \brief �������.
	 */
	int Capacity;

	/**
	 * \brief ����� ����� �����.
	 */
	const int GrowthFactor = 2;

	/**
	 * \brief ������� ��������� ������ Stack
	 */
	Stack()
	{
		Buffer = new int[4];
		Top = 0;
		Capacity = 4;
	}
};

/**
 * \brief ��������� ���� ����������.
 * \param size ������.
 * \return ���������� ����.
 */
Stack* InitStack(int size);

/**
 * \brief ��������� ������� � ����.
 * \param stack ����.
 * \param data ��������.
 * \return ���������� true, ���� ������� ��� ��������, ����� false.
 */
bool PushStack(Stack* stack, int data);

/**
 * \brief ����������� ������� �� �����.
 * \param stack ����.
 * \return ���������� �������� ���������� ��������.
 */
int PopStack(Stack* stack);

/**
 * \brief ������� ����.
 * \param stack ����.
 */
void DeleteStack(Stack* stack);

/**
 * \brief �������� ������ �����.
 * \param stack ����.
 */
void Resize(Stack* stack);