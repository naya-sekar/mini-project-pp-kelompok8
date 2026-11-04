# SPLIT BILL SYSTEM
 Kelompok 8

 1. ⭐ Muhammad Abizar Saputra (2617051043)
 2. Daffa Fawwazidlan Hasibuan (2617051008)
 3. Naya Sekar FQ (2617051040)
 4. Edgina Daratertia (2617051018)
 5. Dechasshyfa Adharisma (2617051029)

Tema Project    : Sistem Split Bill
Latar Belakang  : Dalam kehidupan sehari-hari, kegiatan makan bersama atau membeli kebutuhan kelompok sering kali berakhir dengan kesulitan menentukan berapa yang harus dibayar setiap orang. Kesulitan ini muncul karena pesanan tiap orang berbeda, sementara tagihan juga dipengaruhi oleh diskon, biaya layanan, dan pajak. Perhitungan manual memakan waktu, rawan terjadi kekeliruan, dan hasilnya kurang transparan. Oleh karena itu, diperlukan sebuah program yang dapat menghitung pembagian biaya secara otomatis, akurat dan tepat.

skenario :
Empat teman kuliah ( jena, piya, lala, dan mika ) makan bersama di kafe. Jena menalangi pembayaran ke kasir. kafe sedang memberi promo diskon 10% untuk seluruh pesanan, dan struk dikenai pajak serta service change 15%. lala sudah memberikan uang muka RP 10.000 kepada jena. program ini akan menghitung berapa yang harus ditransfer tiap orang ke jena.

data pesanan:
jena : nasi goreng 25.000 dan es teh 7.000 subtotal 32.000 dp 0

piya : mie ayam 20.000 dan es jeruk 10.000 subtotal 30.000 dp 0

lala : ayam geprek 15.000 dan air mineral 5.000 subtotal 20.000 dp 10.000

mika : salad 20.000 dan kopi 8.000 subtotal 28.000 dp 0 

pesanan bersama : kentang goreng 24.000 dan pisang goreng 20.000 = 44.000 dibagi rata sehingga bagian tiap orang Rp 11.000

aturan pembagian :
1. tagihan dasar tiap orang = pesanan pribadi + bagian pesanan bersama
2. diskon dalam persen (0-100) dihitung dari tagihan dasar masing - masing, sehingga otomatis propodional
3. pajak dan service (persen) dihitung setelah diskon
4. hasil dibulatkan ke atas satuan rupiah
5. uang muka (dp) dikurangi dari kewajiban orang yang bersangkutan
6. penalangan dicari berdasarkan nama. ia tidak tranfer dan hanya menerima dari yang lain

rumus perhitungan
dasar = pribadi[i] + (totalbersama / jumlah)
diskon = dasar * persendiskon / 100
akhir = (dasar - diskon) * (1 + persenpajak / 100)
tagihan = bulatkankeatas(akhir) - dp[i]
 
