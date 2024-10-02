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
	* @brief メモリを確保する。
	*
	* @details 空いているメモリを確保する。
	* @details 確保できない場合はnullptrを返す。
	*
	* @return T* 確保したメモリのポインタ
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
	* @brief メモリを解放する。
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
