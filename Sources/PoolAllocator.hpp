#pragma once

#include "Card.hpp"

template<class T, size_t MAX_SIZE> class PoolAllocator {
public:
	PoolAllocator() {
		this->free = nullptr;
		this->pool = new Block[MAX_SIZE];

		for (size_t i = 0; i < MAX_SIZE; i++) {
			Block* pointer = static_cast<Block*>(&this->pool[i]);
			pointer->next = this->free;
			this->free = pointer;
		}
	}

	~PoolAllocator() {
		for (size_t i = 0; i < MAX_SIZE; i++) {
			this->Deallocate(reinterpret_cast<T*>(&this->pool[i]));
		}
		delete[] this->pool;
	}

	/*
	* @brief ���������m�ۂ���B
	*
	* @details �󂢂Ă��郁�������m�ۂ���B
	* @details �m�ۂł��Ȃ��ꍇ��nullptr��Ԃ��B
	*
	* @return T* �m�ۂ����������̃|�C���^
	*/
	T* Allocate() {
		if (this->free == nullptr) {
			return nullptr;
		}

		Block* pointer = this->free;
		this->free = this->free->next;
		return reinterpret_cast<T*>(pointer);
	}

	/*
	* @brief ���������������B
	*/
	void Deallocate(T* pointer) {
		if (pointer == nullptr) {
			return;
		}

		Block* block = reinterpret_cast<Block*>(pointer);
		block->next = this->free;
		this->free = block;
	}

private:
	struct Block {
		T data;
		Block* next;
	};
	Block* free;
	Block* pool;
};
