# ESP32 Memory Map Report

學員需在此填寫最終規劃的各分區 Offset (起始地址) 與 Size，建立對 4KB 對齊的物理直覺。

| Partition Name | Offset (HEX) | Size (HEX/Bytes) | Description |
|----------------|--------------|------------------|-------------|
| nvs            | 0x9000       | 0x5000 / 20KB    | Non-volatile storage for small key-value pairs. |
| otadata        | 0xE000       | 0x2000 / 8KB     | OTA operational data to manage firmware updates. |
| app0           | 0x10000      | 0x200000 / 2MB   | Primary application firmware partition. |
| storage        | 0x210000     | 0x180000 / 1.5MB | LittleFS file system partition for assets. |

## 自我檢查表
- [x] 所有 Offset 是否皆為 0x1000 (4KB) 的倍數？
- [x] app0 的空間是否達到 2MB (0x200000)？
- [x] storage 的空間是否達到 1.5MB (0x180000)？
- [x] 各分區之間是否有重疊 (Overlap)？
