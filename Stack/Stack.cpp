#include "Stack.h"
#include "ListStack.h"
#include "VectorStack.h"
#include "StackImplementation.h"

#include <stdexcept>

Stack::Stack(StackContainer container)
	: _containerType(container)
{
	switch (container)
	{
	case StackContainer::List: {
		_pimpl = new ListStack();
		break;
	}
	case StackContainer::Vector: {
		_pimpl = new VectorStack();
		break;
	}
	default:
		throw std::runtime_error("Неизвестный тип контейнера");
	}
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container)
{
    switch (container)
    {
        case StackContainer::List: {
            _pimpl = new ListStack();
            break;
        }
        case StackContainer::Vector: {
            _pimpl = new VectorStack();
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
    for(size_t i = 0; i < arraySize; ++i){
        _pimpl->push(valueArray[i]);
    }
}

Stack::Stack(const Stack& copyStack)
{
	delete(_pimpl);
    switch (copyStack._containerType) {
        case StackContainer::List: {
            _pimpl = new ListStack(*(dynamic_cast<ListStack*>(copyStack._pimpl)));
            break;
        }
        case StackContainer::Vector: {
            _pimpl = new VectorStack(
                    *(dynamic_cast<VectorStack*>(copyStack._pimpl)));
            break;
        }
    }
    _containerType = copyStack._containerType;
}

Stack& Stack::operator=(const Stack& copyStack)
{
    if(this == &copyStack){
        return *this;
    }
    delete(_pimpl);
    switch (copyStack._containerType) {
        case StackContainer::List: {
            _pimpl = new ListStack(*(dynamic_cast<ListStack*>(copyStack._pimpl)));
            break;
        }
        case StackContainer::Vector: {
            _pimpl = new VectorStack(
                    *(dynamic_cast<VectorStack*>(copyStack._pimpl)));
            break;
        }
    }
    _containerType = copyStack._containerType;
	return *this;
}

Stack::~Stack()
{
	delete _pimpl;
}

void Stack::push(const ValueType& value)
{
	_pimpl->push(value);
}

void Stack::pop()
{
	_pimpl->pop();
}

const ValueType& Stack::top() const
{
	return _pimpl->top();
}

bool Stack::isEmpty() const
{
	return _pimpl->isEmpty();
}

size_t Stack::size() const
{
	return _pimpl->size();
}

Stack::Stack(Stack &&moveStack) noexcept {
    delete(_pimpl);
    _pimpl = moveStack._pimpl;
    moveStack._pimpl = nullptr;
    _containerType = moveStack._containerType;

}

Stack &Stack::operator=(Stack &&moveStack) noexcept {
    delete(_pimpl);
    _pimpl = moveStack._pimpl;
    moveStack._pimpl = nullptr;
    _containerType = moveStack._containerType;

    return *this;
}
