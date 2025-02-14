 Mahalle Değerlendirme ve Toplu Taşıma Hattı Önerisi
Bu C programı, farklı kriterleri değerlendirerek en uygun toplu taşıma hattının hangi mahalleye kurulması gerektiğini belirler. Softmax normalizasyonu ve ağırlıklı skor hesaplama yöntemi kullanılarak mahalleler arasında karşılaştırma yapılır.

🚀 Özellikler:

✔ Softmax Normalizasyonu ile kriterlerin etkisi ile dengelemeyi amaçlar.
✔ Ağırlıklandırılmış Skor Hesaplama ile mahallelerin uygunluk puanı hesaplanır.
✔do-while yapısı kullanılarak verimli bir hesaplama sağlanır.

📊Kriterler:

🏠 Nüfus (daha yüksek = avantaj)
🏢 İşletme sayısı (daha yüksek = avantaj)
💰 Ortalama konut fiyatı (daha yüksek = dezavantaj)
🚦 Trafik yoğunluğu (daha yüksek = dezavantaj)
🚋 Toplu taşıma ihtiyacı (daha yüksek = avantaj)

🏆 Çıktı:

Program, her mahalle için toplam skoru hesaplar ve en uygun mahalleyi önerir.

🎯 Çıktı Örneği:

Mahallelerin Toplam Skorları:
Karakas Mahallesi: 0.5123
Karacaibrahim Mahallesi: 0.4789
Bademlik Mahallesi: 0.5094

En uygun toplu taşıma hattı için önerilen mahalle: Karakas Mahallesi
