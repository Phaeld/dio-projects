from PIL import Image, ImageFilter

def apply_blur(image_path, radius):
    image = Image.open(image_path)
    blurred_image = image.filter(ImageFilter.GaussianBlur(radius))
    return blurred_image

def apply_edge_detection(image_path):
    image = Image.open(image_path)
    edged_image = image.filter(ImageFilter.FIND_EDGES)
    return edged_image
