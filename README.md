# STM32-ADXL345-I2C-IvmeOlcer
STM32 mikrodenetleyici ile ADXL345 ivmeölçer sensörü I2C üzerinden haberleştirilerek X, Y, Z eksen verileri okunur ve UART üzerinden seri terminale gönderilir. Temel sensör haberleşmesi ve veri işleme örneğidir.
# STM32 ile ADXL345 İvmeölçer Kullanımı (I2C)

Bu proje, STM32 mikrodenetleyici kullanılarak ADXL345 ivmeölçer sensöründen I2C protokolüyle veri okumayı ve okunan X, Y, Z eksen verilerini UART ile seri port üzerinden aktarmayı amaçlar.

## 🧰 Kullanılan Donanımlar
- STM32 Nucleo Board (örneğin: F401RE)
- ADXL345 İvmeölçer Sensörü (I2C bağlantılı)
- USB-TTL dönüştürücü (UART görüntüleme için, opsiyonel)

## 🔌 Bağlantılar
| STM32 Pin | ADXL345 Pin |
|-----------|-------------|
| 3.3V      | VCC         |
| GND       | GND         |
| PB6       | SDA         |
| PB7       | SCL         |

> UART TX: PA2 — Seri terminalde veri görüntülemek için kullanılır (USART2)

## ⚙️ Proje Özellikleri
- I2C ile ADXL345 haberleşmesi (`hi2c1`)
- UART üzerinden veri iletimi (`huart2`)
- X, Y, Z eksenlerinden 16-bit ivme verisi okuma
- `HAL_I2C_Mem_Read()` kullanılarak register okuma

## 📂 Dosya Yapısı

/Core
│
├── Inc
│ └── adxl345.h → ADXL sensör fonksiyon prototipleri
│
├── Src
│ └── adxl345.c → Sensör okuma ve başlatma işlemleri
│ └── main.c → Ana döngüde veri okuma ve UART ile gönderme


## 🛠️ Derlemek için Gerekli Ortam
- STM32CubeIDE
- STM32 HAL Kütüphanesi (I2C, UART etkin)
- Geliştirme kartına uygun clock ayarları (HSE/HSI)

## 📌 Ek Bilgiler
- ADXL345 cihaz adresi: `0x53 << 1 
- `DEVID` register’ı `0x00` adresinden okunarak sensör doğrulaması yapılır
- `0x32` adresinden itibaren X, Y, Z eksenlerine ait 6 byte veri okunur

---

Proje, gömülü sistemlerde sensör haberleşmesini öğrenmek isteyenler için temel bir örnektir.
