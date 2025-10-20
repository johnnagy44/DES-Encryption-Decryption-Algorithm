# 🔐 DES Encryption & Decryption Tool

### CSE451 – Computer & Network Security

---

## 📘 Overview

This project implements the **Data Encryption Standard (DES)** algorithm in **C** using the **Electronic Codebook (ECB)** mode.
It provides a command-line interface to encrypt and decrypt files using a specified key.

---

## ⚙️ Building

Compile the project using the provided **Makefile**:

```bash
make
```

Rebuild from scratch:

```bash
make clean && make
```

This creates an executable named `des`.

---

## ▶️ Usage

```
./des <mode> <keyfile> <inputfile> <outputfile>
```

| Parameter      | Description                                  |
| -------------- | -------------------------------------------- |
| `<mode>`       | `"e"` for encryption or `"d"` for decryption |
| `<keyfile>`    | File containing the 8-byte DES key           |
| `<inputfile>`  | Input file to process                        |
| `<outputfile>` | Output file to store the result              |

### Example

```
./des e key.txt input.txt output.txt
```

---

## 🔒 Implementation Notes

* **Mode:** ECB (Electronic Codebook)
* **Block size:** 64 bits
* **Key size:** 64 bits (56 effective bits + 8 parity bits)
* **Rounds:** 16
* **Padding:** None (input size must be a multiple of 8 bytes)
* **I/O Functions:** `fopen`, `fread`, `fwrite`, `fclose`

---

## 🧩 Project Structure

```
📂 DES-Project/
 ├── src/
 │   ├── des.c
 │   ├── keygen.c
 │   ├── feistel.c
 │   ├── permutation.c
 │   ├── utils.c
 │
 ├── include/
 │   ├── des.h
 │   ├── keygen.h
 │   ├── feistel.h
 │   ├── permutation.h
 │   ├── utils.h
 │
 ├── Makefile
 ├── README.md
```

---

## ⚡ Performance

* Optimized for speed using bitwise operations.
* Processes files in 64-bit blocks with minimal overhead.

---

## ⚠️ Notes

* Input size **must be a multiple of 8 bytes**.
* Only **ECB** mode is implemented.
* Intended for **educational purposes** — not for real-world encryption.

---

## 🧠 References

* [DES Supplementary Material – Wikipedia](https://en.wikipedia.org/wiki/DES_supplementary_material)
* [FIPS PUB 46-3 – Data Encryption Standard](https://csrc.nist.gov/publications/detail/fips/46-3/final)

---
