#ifdef _WIN32
#include <mem.h>
#else
#include <string.h>
#endif

#include "linear_sequence.h"

#define _START_SIZE_PHYS 1 // Количество памяти, выделяемое под свежий массив (в sizeof(LSQ_BaseTypeT))

#define _RESIZE_FACTOR 2

#define _RESIZE_M 16777216    // применяется _RESIZE_FACTOR^(-1)
#define _RESIZE_L 56623104  // применяется _RESIZE_FACTOR^(-2)
#define _RESIZE_XL 172800000  // применяется _RESIZE_FACTOR^(-3)
#define _RESIZE_XXL 246037500 // применяется _RESIZE_FACTOR^(-4)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define NULLPTR(x) ((x) == NULL)
#define _HANDLE_INVALID(x) ((x) == LSQ_HandleInvalid || NULLPTR(x))
// Основное отличие верхнего от нижнего -- LSQ_HandleInvalid может ВНЕЗАПНО поменяться, и тогда придётся отлавливать
// хэндл и на LSQ_HandleInvalid, и на нулевой указатель, если какой-нибудь дегенерат пихнёт именно NULL

typedef struct {
    LSQ_BaseTypeT *data;
    LSQ_IntegerIndexT size_logic;
    size_t size_phys;
} _ContainerT;

typedef struct {
    _ContainerT *array;
    LSQ_IntegerIndexT index;
} _IteratorT;

// Функции для внутреннего использования
int _container_is_full(_ContainerT *x) {
    return x->size_logic == x->size_phys;
}
int _container_is_empty_enough(_ContainerT *x) {
    return x->size_logic < x->size_phys / (_RESIZE_FACTOR*_RESIZE_FACTOR);
}
int _container_get_resize_factor(_ContainerT *x) {
    if (x->size_phys >= _RESIZE_XXL) {
        return _RESIZE_FACTOR*_RESIZE_FACTOR*_RESIZE_FACTOR*_RESIZE_FACTOR;
    } else if (x->size_phys >= _RESIZE_XL) {
        return _RESIZE_FACTOR*_RESIZE_FACTOR*_RESIZE_FACTOR;
    } else if (x->size_phys >= _RESIZE_L) {
        return _RESIZE_FACTOR*_RESIZE_FACTOR;
    } else if (x->size_phys >= _RESIZE_M) {
        return _RESIZE_FACTOR;
    } else {
        return 1;
    }
}
void _container_set_size(_ContainerT *c, size_t s) {
    if (NULLPTR(c)) {
        return;
    }
    s = MAX(s, _START_SIZE_PHYS);
    c->size_phys = s;
    c->data = realloc(c->data, s * sizeof(LSQ_BaseTypeT));
    // Если реаллок не выйдет, то [s]Сайори помрёт[/s] E N D .
}

// Создать/удалить массив
extern LSQ_HandleT LSQ_CreateSequence(void) {
    _ContainerT *array = calloc(1, sizeof(_ContainerT));
    if (NULLPTR(array)) {
        return LSQ_HandleInvalid;
    }
    array->size_phys = _START_SIZE_PHYS;
    array->size_logic = 0;
    array->data = calloc(_START_SIZE_PHYS, sizeof(LSQ_BaseTypeT));
    if (NULLPTR(array->data)) {
        free(array);
        return LSQ_HandleInvalid;
    }
    return array;
}
extern void LSQ_DestroySequence(LSQ_HandleT handle) {
    if (_HANDLE_INVALID(handle)) {
        return;
    }
    _ContainerT *array = (_ContainerT *) handle;
    if (!NULLPTR(array->data)) {
        free(array->data);
    }
    free(handle);
}

// Получить размер
extern LSQ_IntegerIndexT LSQ_GetSize(LSQ_HandleT handle) {
    if (_HANDLE_INVALID(handle)) {
        return 0;
    }
    return ((_ContainerT *) handle)->size_logic;
}

// Работа с итераторами
extern LSQ_BaseTypeT *LSQ_DereferenceIterator(LSQ_IteratorT iterator) {
    if (!LSQ_IsIteratorDereferencable(iterator)) {
        return LSQ_HandleInvalid;
    }
    _IteratorT *it = (_IteratorT *) iterator;
    return &it->array->data[it->index];
}
extern int LSQ_IsIteratorDereferencable(LSQ_IteratorT iterator) {
    if (_HANDLE_INVALID(iterator)) {
        return 0;
    }
    _IteratorT *it = ((_IteratorT *) iterator);
    return it->index >= 0 && it->index < it->array->size_logic;
}
extern int LSQ_IsIteratorPastRear(LSQ_IteratorT iterator) {
    if (_HANDLE_INVALID(iterator)) {
        return 0;
    }
    _IteratorT *it = ((_IteratorT *) iterator);
    return it->index == it->array->size_logic;
}
extern int LSQ_IsIteratorBeforeFirst(LSQ_IteratorT iterator) {
    if (_HANDLE_INVALID(iterator)) {
        return 0;
    }
    return ((_IteratorT *) iterator)->index == -1;
}
extern LSQ_IteratorT LSQ_GetElementByIndex(LSQ_HandleT handle, LSQ_IntegerIndexT index) {
    if (_HANDLE_INVALID(handle)) {
        return LSQ_HandleInvalid;
    }
    _IteratorT *it = calloc(1, sizeof(_IteratorT));
    if (NULLPTR(it)) {
        return LSQ_HandleInvalid;
    }
    it->array = (_ContainerT *) handle;
    it->index = MAX(MIN(index, it->array->size_logic), -1);
    return it;
}
extern LSQ_IteratorT LSQ_GetFrontElement(LSQ_HandleT handle) {
    return LSQ_GetElementByIndex(handle, 0);
}
extern LSQ_IteratorT LSQ_GetPastRearElement(LSQ_HandleT handle) {
    if (_HANDLE_INVALID(handle)) {
        return LSQ_HandleInvalid;
    }
    return LSQ_GetElementByIndex(handle, ((_ContainerT *) handle)->size_logic);
}
extern void LSQ_AdvanceOneElement(LSQ_IteratorT iterator) {
    LSQ_ShiftPosition(iterator, 1);
}
extern void LSQ_RewindOneElement(LSQ_IteratorT iterator) {
    LSQ_ShiftPosition(iterator, -1);
}
extern void LSQ_ShiftPosition(LSQ_IteratorT iterator, LSQ_IntegerIndexT shift) {
    if (_HANDLE_INVALID(iterator)) {
        return;
    }
    LSQ_SetPosition(iterator, ((_IteratorT *) iterator)->index + shift);
}
extern void LSQ_SetPosition(LSQ_IteratorT iterator, LSQ_IntegerIndexT pos) {
    if (_HANDLE_INVALID(iterator)) {
        return;
    }
    _IteratorT *it = ((_IteratorT *) iterator);
    it->index = MAX(MIN(pos, it->array->size_logic), -1);
}
extern void LSQ_DestroyIterator(LSQ_IteratorT iterator) {
    if (!_HANDLE_INVALID(iterator)) {
        free(iterator);
    }
}

// Добавление элементов
extern void LSQ_InsertFrontElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {
    LSQ_IteratorT it = LSQ_GetFrontElement(handle);
    LSQ_InsertElementBeforeGiven(it, element);
    LSQ_DestroyIterator(it);
}
extern void LSQ_InsertRearElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {
    LSQ_IteratorT it = LSQ_GetPastRearElement(handle);
    LSQ_InsertElementBeforeGiven(it, element);
    LSQ_DestroyIterator(it);
}
extern void LSQ_InsertElementBeforeGiven(LSQ_IteratorT iterator, LSQ_BaseTypeT newElement) {
    if (_HANDLE_INVALID(iterator)) {
        return;
    }
    _IteratorT *it = (_IteratorT *) iterator;
    _ContainerT *array = it->array;

    if (_container_is_full(array)) {
        int resize_factor = _container_get_resize_factor(array);
        _container_set_size(array, array->size_phys + array->size_phys / resize_factor);
    }
    array->size_logic++;

    if (it->index != array->size_logic) {
        memmove(&array->data[it->index + 1], &array->data[it->index],
                (array->size_logic - it->index - 1) * sizeof(LSQ_BaseTypeT));
    }

    array->data[it->index] = newElement;
}

// Удаление элементов
extern void LSQ_DeleteFrontElement(LSQ_HandleT handle) {
    LSQ_IteratorT it = LSQ_GetFrontElement(handle);
    LSQ_DeleteGivenElement(it);
    LSQ_DestroyIterator(it);
}
extern void LSQ_DeleteRearElement(LSQ_HandleT handle) {
    LSQ_IteratorT it = LSQ_GetPastRearElement(handle);
    LSQ_RewindOneElement(it);
    LSQ_DeleteGivenElement(it);
    LSQ_DestroyIterator(it);
}
extern void LSQ_DeleteGivenElement(LSQ_IteratorT iterator) {
    if (!LSQ_IsIteratorDereferencable(iterator)) {
        return;
    }
    _IteratorT *it = (_IteratorT *) iterator;
    _ContainerT *array = it->array;

    if (array->size_logic <= 0) {
        return;
    }
    array->size_logic--;

    memmove(&array->data[it->index], &array->data[it->index + 1],
            (array->size_logic - it->index) * sizeof(LSQ_BaseTypeT));

    if (_container_is_empty_enough(array)) {
        _container_set_size(array, array->size_phys / _RESIZE_FACTOR);
    }
}
