import cv2

localities = ["biblioteca", "bloco3", "entrada"]

for locality in localities:
    i = 1
    while(i <= 3):
        fname = 'query ({})'.format(i)
        path = 'original/{}.jpg'.format(fname)
        newImagePath = 'pgm/{}.pgm'.format(fname)

        print(fname, path, newImagePath)

        print("Convertendo arquivo em PGM...")
        img = cv2.imread(path, cv2.IMREAD_GRAYSCALE)

        width, height = img.shape[:2] 
        print(width, height)
        width = width // 6
        height = height // 6

        print(width, height)

        img = cv2.resize(img, (width, height))
        cv2.imwrite(newImagePath, img, [cv2.IMWRITE_PXM_BINARY, 0])

        print("Arquivo PGM gerado e salvo.\n\n")

        i += 1
