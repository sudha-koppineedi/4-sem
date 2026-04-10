import cv2

img = cv2.imread("input.jpg")

if img is None:
    print("Image not found")
else:
    cv2.imshow("Test Image", img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
