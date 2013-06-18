mavlink
=======

Thư viện mavlink sử dụng trong các dự án của Gremsy.
Giới thiệu: 
 mavlink là chuẩn truyền được sử dụng rộng rãi trong điều khiển thiết bị, đặc biệt trong lĩnh vực điều khiển uav.
 Thư viện mavlink được phát triển bởi cộng đồng:
  mavlink website: http://qgroundcontrol.org/mavlink/start
  
Sử dụng trong dự án:
	Đối với firmware: #include "mavlink.h", đường dẫn có thể thay đổi để chỉ đến file mavlink.h trong thu mục dự án, không sử dụng mavlink.h trong thư mục common.
		Chú ý: 
		  + khi compile trong Keil uVision, có thể gặp lỗi "inline"
		    --> Khắc phục: thay inline thành __inline (thêm 2 gạch dưới)
		  + Với Keil V4.7, có thể gặp thêm lỗi về union
		    --> khắc phục: thêm #pragma anon_unions vào trước khai báo struct, union 
			  Tham khảo: http://www.keil.com/support/man/docs/armccref/armccref_Ciajccbj.htm
	Đối với Software (sử dụng QtCreator): 
        - Thêm #include vào trong các file có sử dụng hàm của mavlink.
		- Trong file .pro:
		  + Thêm INCLUDEPATH += 
		     Ví dụ: 
			    INCLUDEPATH += thirdParty/mavlink/v1.0/common \
							   thirdParty/mavlink/v1.0/gremsygimbal

Cấu trúc thư mục:
  mavlink\
    v1.0\							# hiện tại sử dụng phiên bản 1.0
		common\						# thư mục chứa các thư viện chuẩn của mavlink						
		gremsygimbal\				# thư mục chứa các file thư viện của từng dự án, ở đây là gimbal
		checksum.h					# file chuẩn của mavlink
		mavlink_helpers.h			# file chuẩn của mavlink
		mavlink_types.h				# file chuẩn của mavlink
		protocol.h					# file chuẩn của mavlink		
	README.md
