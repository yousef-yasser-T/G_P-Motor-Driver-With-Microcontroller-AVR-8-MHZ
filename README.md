

https://github.com/user-attachments/assets/9b147585-faa7-45e8-9bc7-135974b4e8c8

# 🚗 Smart Obstacle-Avoiding Car | سيارة ذكية تتفادى العوائق (AVR)

مشروع **Motor Driver Robot Car** مبني على متحكم AVR (ATmega32/16)، بيتحكم في عربية بأربع عجلات باستخدام موتورين DC، ويقدر يتفادى العوائق أوتوماتيكيًا بمستشعر Ultrasonic، مع إمكانية التحكم اليدوي عن طريق Push Buttons، وعرض الحالة والمسافة على شاشة LCD، وتنبيه صوتي بالـ Buzzer عند اقتراب عائق.

---

## 📋 جدول المحتويات
- [نظرة عامة](#-نظرة-عامة)
- [فريق العمل](#-فريق-العمل)
- [مكونات الهاردوير](#-مكونات-الهاردوير)
- [هيكل المشروع (Layered Architecture)](#-هيكل-المشروع-layered-architecture)
- [توزيع البورتات والبنات (Pinout)](#-توزيع-البورتات-والبنات-pinout)
- [شرح المكتبات (Modules)](#-شرح-المكتبات-modules)
- [منطق عمل السيارة (Logic)](#-منطق-عمل-السيارة-logic)
- [طريقة التشغيل](#-طريقة-التشغيل)
- [تحسينات مستقبلية](#-تحسينات-مستقبلية)

---

## 🔎 نظرة عامة

العربية بتشتغل بالمبدأ التالي:
1. تقيس المسافة باستمرار باستخدام حساس **Ultrasonic HC-SR04**.
2. لو المسافة أقل من أو تساوي **20 سم**، البازر (Buzzer) يشتغل تحذيرًا من وجود عائق، وتتوقف العربية عن الحركة.
3. لو المسافة أكبر من 20 سم، يقدر المستخدم يتحكم في العربية عن طريق 4 أزرار (**Forward / Backward / Left / Right**).
4. كل التفاصيل (المسافة + الحالة الحالية للعربية) بتتعرض Live على شاشة **LCD 16x2**.

---

## 👥 فريق العمل

**Group 2**

| # | الاسم |
|---|-------|
| 1 | Khaled Mohamed Hamed Abdullah |
| 2 | Hussein Mohamed Hussein Mohamed |
| 3 | Yusuf Yasser Hussein Abdelhafeez |
| 4 | Ammar Mohey Mohamed Mohamed |

---

## 🛠️ مكونات الهاردوير

| المكون | العدد | الوظيفة |
|---|---|---|
| ATmega32/16 (AVR Microcontroller) | 1 | العقل المدبر للمشروع |
| HC-SR04 Ultrasonic Sensor | 1 | قياس المسافة وتفادي العوائق |
| LCD 16x2 (4-bit mode) | 1 | عرض المسافة وحالة الحركة |
| DC Motor + Motor Driver (L298N أو مشابه) | 2 | تحريك العجلات (يمين / شمال) |
| Buzzer | 1 | تنبيه صوتي عند اقتراب عائق |
| Push Buttons | 4 | التحكم اليدوي في اتجاه الحركة |
| مصدر تغذية (Battery Pack) | 1 | تغذية الدائرة والموتورات |

---

## 🧱 هيكل المشروع (Layered Architecture)

المشروع مبني على تصميم **Layered Architecture** المعروف في أنظمة الـ AVR الاحترافية، بحيث كل طبقة معزولة عن التانية:

```
📁 Project
├── 📁 APP
│   └── main.c                  # المنطق الرئيسي للتطبيق
├── 📁 HAL (Hardware Abstraction Layer)
│   ├── LCD/          (LCD.c / LCD.h)
│   ├── Buzzer/        (Buzzer.c / Buzzer.h)
│   ├── DC_Motor/      (DC_Motor.c / DC_Motor.h)
│   ├── PB/            (PB.c / PB.h)
│   └── Ultrasonic/    (Ultrasonic.c / Ultrasonic.h)
├── 📁 MCAL (Microcontroller Abstraction Layer)
│   ├── DIO/           (التحكم في البورتات والبنات)
│   └── Timer1/        (لحساب زمن استقبال الإيكو بتاع الحساس)
└── 📁 LIB
    ├── STd_Types.h    # تعريفات الأنواع القياسية (u8, u32, ...)
    └── BitMath.h      # ماكروهات التعامل مع البتات
```

الفكرة إن كل درايفر (HAL) بيكلم طبقة الـ MCAL بس، ومحدش بيتعامل مباشرة مع الـ Registers غير طبقة الـ MCAL، وده بيخلي الكود قابل لإعادة الاستخدام وسهل الصيانة.

---

## 🔌 توزيع البورتات والبنات (Pinout)

### 1) شاشة LCD (4-bit Mode)

| الوظيفة | البورت | البن |
|---|---|---|
| Data Pins (D4-D7) | PORTA | PIN4, PIN5, PIN6, PIN7 |
| RS | PORTB | PIN0 |
| RW | PORTB | PIN1 |
| Enable (E) | PORTB | PIN2 |

### 2) حساس المسافة Ultrasonic

| الوظيفة | البورت | البن |
|---|---|---|
| Trigger (TRIG) | PORTD | PIN1 |
| Echo (ICP1 - Timer1 Input Capture) | Timer1 ICP Pin | حسب دايتشيت المتحكم |

### 3) الموتورات (Motor Driver)

| الموتور | الوظيفة | البورت | البن |
|---|---|---|---|
| Motor 1 (يمين) | IN1 | PORTC | PIN4 |
| Motor 1 (يمين) | IN2 | PORTC | PIN5 |
| Motor 2 (شمال) | IN1 | PORTC | PIN6 |
| Motor 2 (شمال) | IN2 | PORTC | PIN7 |

### 4) البازر (Buzzer)

| الوظيفة | البورت | البن |
|---|---|---|
| Buzzer Signal | PORTD | PIN5 |

### 5) أزرار التحكم (Push Buttons)

| الزر | الوظيفة | البورت | البن |
|---|---|---|---|
| PB1 | Forward (للأمام) | PORTC | PIN0 |
| PB2 | Backward (للخلف) | PORTC | PIN1 |
| PB3 | Left (يمين/يسار حسب التوصيل) | PORTC | PIN2 |
| PB4 | Right | PORTC | PIN3 |

> **ملاحظة:** الأزرار متوصلة بطريقة Pull-up داخلي (Active Low)، يعني الزرار بيُعتبر مضغوط لما تقرأ عليه قيمة LOW (0).

---

## 📦 شرح المكتبات (Modules)

### `LCD` — التحكم في شاشة الكريستال
- `HLCD_voidInit()`: تهيئة الشاشة (4-bit mode).
- `HLCd_voidSendData()`: إرسال حرف واحد للعرض.
- `HLCD_voidSendCmd()`: إرسال أمر تحكم (زي مسح الشاشة، تحريك المؤشر).
- `HLCD_voidDisplayStr()`: عرض نص كامل (String).
- `HLCD_voidClrDisplay()`: مسح الشاشة.
- `HLCD_voidMoveCursor()`: تحريك المؤشر لصف وعمود معينين.
- `HLCD_voidDisplayCustomChar()`: إنشاء وعرض حرف مخصص (Custom Character).

### `Ultrasonic` — حساس المسافة
- `HUltrasonic_voidInit()`: تهيئة بن الـ Trigger وتهيئة الـ Timer1.
- `HUltrasonic_u32CalcDistance()`: إرسال نبضة Trigger، وحساب المسافة بالسنتيمتر بناءً على زمن استقبال الـ Echo عن طريق الـ Timer1 (باستخدام معادلة السرعة: المسافة = (17300 × الزمن) / 1,000,000).

### `DC_Motor` — التحكم في الموتورات
- `HDCM_voidInit()`: تهيئة بنات الموتور كمخرجات.
- `HDCM_voidCW()`: تدوير الموتور مع عقارب الساعة (للأمام).
- `HDCM_voidCCW()`: تدوير الموتور عكس عقارب الساعة (للخلف).
- `HDCM_voidStop()`: إيقاف الموتور.

### `Buzzer` — جرس التنبيه
- `HBUZZER_voidInit()`: تهيئة بن البازر كمخرج.
- `HBUZZER_voidTurnOn()` / `HBUZZER_voidTurnOff()`: تشغيل/إطفاء البازر.
- `HBUZZER_voidTogStatus()`: عكس حالة البازر.

### `PB` — أزرار التحكم
- `HPB_voidInit()`: تهيئة البن كمدخل مع تفعيل الـ Pull-up.
- `HPB_u8GetStatues()`: قراءة حالة الزرار مع عمل Debounce بسيط بتأخير 20ms.
- `HState_voidStateCar()`: دالة مساعدة تحدد اتجاه حركة العربية (Forward/Backward/Left/Right/Stop) عن طريق التحكم في 4 بنات مباشرة.

---

## ⚙️ منطق عمل السيارة (Logic)

```
Loop:
    اقرأ المسافة من الحساس
    اعرض المسافة على LCD

    لو المسافة >= 20 سم:
        لو اتضغط زرار Forward   → الموتورين يدوروا للأمام
        لو اتضغط زرار Backward  → الموتورين يدوروا للخلف
        لو اتضغط زرار Left      → موتور واحد يدور، التاني واقف (لف يمين)
        لو اتضغط زرار Right     → عكس الحالة اللي فوق (لف شمال)
        لو مفيش زرار متضغوط    → العربية تقف (Stop)
    لو المسافة <= 20 سم:
        العربية تقف إجباريًا
        البازر يشتغل تحذيرًا

    تأخير 2 ثانية ثم تكرار الحلقة
```

---

## ▶️ طريقة التشغيل

1. افتح المشروع على **Atmel Studio / Microchip Studio** أو أي IDE بيدعم AVR-GCC.
2. تأكد إن الـ MCU المختار في إعدادات المشروع مطابق للمتحكم الفعلي (ATmega32/16).
3. وصّل الهاردوير حسب [جدول البورتات](#-توزيع-البورتات-والبنات-pinout) أعلاه.
4. اعمل Build للمشروع، وبعدين ارفع الكود (Flash) على المتحكم باستخدام برمجة AVR (USBasp أو ما شابه).
5. شغّل الدائرة، وهتلاقي المسافة ظاهرة على الشاشة والعربية جاهزة تستقبل أوامرك من الأزرار.

---

## 🚀 تحسينات مستقبلية

- إضافة تحكم عن بعد (Bluetooth / RF) بدل الأزرار.
- تحويل السرعة إلى PWM بدل التشغيل On/Off لتحكم أنعم في السرعة.
- إضافة وضع Auto-Avoid بحيث تلف العربية أوتوماتيكيًا لما تقابل عائق بدل ما تقف بس.
- استبدال الـ Delay-based Debounce بحل مبني على Interrupts لتحسين الأداء.

---

<p align="center">Made with ❤️ by <b>Group 2</b></p>
