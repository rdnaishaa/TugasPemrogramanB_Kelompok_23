<h1>Kelompok 23</h1>

<h2>Anggota Kelompok</h2>

- Adi Nugroho	              (2306208546)
- R. Aisha Syauqi Ramadhani (2306250554)
- Zhafira Zahra Alfarisy		(2306250636)
- Vanesa Kayla Zahra        (23066161901)
- Aliya Rizqiningrum Salamun (2306161813)

<h2>Deskripsi Program</h2>

Program ini menghitung Root Mean Square (RMS) dari sinyal arus :<br><br>

i(t) = 10e^(−t/T) * sin⁡(2πt/T) untuk 0 <= t <= T/2 <br>
i(t) = 0 untuk T/2 < t <= T <br><br>

menggunakan metode integrasi numerik newton-cotes dengan mengimplementasikan rules berikut: <br><br>


    Aturan Trapesium (Trapezoidal Rule) dengan 128 segmen.

    Aturan Simpson 1/3 (*Simpson’s 1/3 Rule*) dengan 32 segmen.

Program terdiri dari function current() yang berisi sinyal arus yang akan dihitung nilai RMS-nya. Selanjutnya terdapat function trapezoidal_rule() dan simpsons_rule() yang akan mengimplementasikan trapezoidal rule dan simpson 1/3 rule pada metode numerik newton-cotes.
Pada trapezoidal rule, periode akan dibagi ke dalam segment-segment yang dimana setiap segment akan mengevaluasi nilai current signal untuk t pada segment tersebut. Hasil perhitungan dari tiap segment akan dijumlahkan untuk mendapat
nilai integral untuk iterasi tersebut. semakin lama segment akan semakin banyak hingga pada iterasi 128, periode akan dibagi ke dalam 128 segment. Program akan berhenti saat iterasi ke 128, dan hasil integral pada iterasi tersebut akan dekat
dengan nilai referensi exact integral dari fungsi sinyal arus.

Untuk simpson 1/3 rule, jumlah iterasi dibatasi hanya sampai 32 dikarenakan metode ini dapat mengoreksi kesalahan lebih cepat dibanding trapezodial rule sehingga dapat mencapai akurasi tinggi dengan jumlah iterasi lebih rendah. simpson rule
bekerja dengan cara memetakan suatu parabola pada setiap 3 titik dari fungsi sinyal arus dalam periodenya. Hal ini berbeda dengan trapezodial rule yang memetakan garis lurus pada tiap 2 titik. Hal ini yang membuat simpson rule lebih cepat
mengoreksi kesalahan.
