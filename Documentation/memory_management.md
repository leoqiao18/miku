# Memory Management

Memory management in Miku mostly boils down to three main parts:

  1. Physical memory management
  2. Virtual memory address management
  3. Heap management

## Virtual Memory Map

| Start      | End        | Size (MiB, KiB) | Description                 |
| ---------- | ---------- | --------------- | --------------------------- |
| 0xC0000000 | 0xC00B8000 | (0, 736)        | unmapped                    |
| 0xC00B8000 | 0xC00BFFFF | (0, 32)         | VGA color text buffer       |
| 0xC00C0000 | 0xC0100000 | (0, 256)        | unmapped                    |
| 0xC0100000 | 0xCFFFFFFF | (255, 0)        | kernel code                 |
| 0xD0000000 | 0xDFFFB000 | (255, 1004)     | kernel heap                 |
| 0xDFFFB000 | 0xDFFFC000 | (0, 4)          | unmapped (guard page)       |
| 0xDFFFC000 | 0xDFFFFFFF | (0, 16)         | kernel stack                |
| 0xE0000000 | 0xEFFFFFFF | (256, 0)        | reserved (drivers?)         |
| 0xF0000000 | 0xFFBFFFFF | (252, 0)        | reserved (new page tables?) |
| 0xFFBFFFFF | 0xFFFFFFFF | (4, 0)          | current page tables         |