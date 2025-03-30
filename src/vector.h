
typedef struct {
  void* data;         // Pointer to allocated data
  size_t unit_size;   // Size of data unit
  int size;           // Number of eliments allocated
  size_t capacity;    // Total allocated space
} Vector;

Vector vector_init(size_t unit_size, int initial_capacity_count); 
void vector_set(Vector* v, int i, void* data_item);
void* vector_get(Vector* v, int i);
void vector_remove(Vector* v, int i);
void vector_push(Vector* v, void* data_item);
void vector_pop(Vector* v);
void vector_unshift(Vector* v, void* data_item);
void vector_shift(Vector* v);
void vector_print(Vector* v);
