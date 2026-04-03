# 🎯 Target Presence Detection in Mixed Audio

Robust Target Presence Detection in Mixed Audio Using ConvTasNet.

---

## 📌 Problem

Instead of full speech recognition or source separation, this project focuses on a simpler and practical task:

> Given a mixed audio signal → **Is the target sound present?**

This is formulated as a binary classification problem.

---

## 🧠 Approach

- Backbone: ConvTasNet  
- Head: Lightweight classification layer  
- Input: Raw waveform  
- Output: Probability of target presence  

The model is trained end-to-end without handcrafted features.

---

## 📊 Dataset

A synthetic dataset was generated using:
- Target audio samples
- Non-target audio samples

### Preprocessing
- Resampled to 8 kHz  
- Segmented into 2-second clips  
- Mixed to simulate real-world scenarios  

---

## 📈 Results

### Test Set (Threshold = 0.50)

| Metric       | Value   |
|-------------|--------|
| Accuracy    | 0.9555 |
| Precision   | 0.9796 |
| Recall      | 0.9673 |
| Specificity | 0.8919 |
| F1-score    | 0.9735 |

---

## ⚙️ Threshold Optimization

- Default threshold: 0.50  
- Optimal threshold: 0.58  

| Metric   | Value   |
|----------|--------|
| Best F1  | 0.9746 |

---

## 🧪 Robustness Test

The system was evaluated under increasing non-target noise:

| Noise Level | Recall |
|------------|--------|
| 10 dB      | 0.74   |
| 100 dB     | 0.06   |

### Insight
- Strong performance under moderate noise  
- Significant degradation under extreme interference  

---

## ⚠️ Limitations

- Sensitive to high noise levels  
- Synthetic dataset limits real-world generalization  
- No explicit noise-robust training techniques used  

# Predict
python predict.py --input sample.wav
