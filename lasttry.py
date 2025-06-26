import tkinter as tk
from tkinter import filedialog, PhotoImage
import subprocess
from PIL import Image, ImageTk

import tkinter as tk
from tkinter import filedialog
import subprocess

def delete_duplicates():
    # Call your C++ function here
    import subprocess
    # compile the C++ code
    subprocess.call(["g++", "redundant.cpp"])
    # run the compiled code
    output = subprocess.check_output("./a.exe")
    # print the output
    print("Output:", output.decode())


def delete_empty():
    # Call your C++ function here
    import subprocess
    # compile the C++ code
    subprocess.call(["g++", "empty_file_check.cpp"])
    # run the compiled code
    output = subprocess.check_output("./a.exe")
    # print the output
    print("Output:", output.decode())

def delete_time():
    # Call your C++ function here
    import subprocess
    # compile the C++ code
    subprocess.call(["g++", "n_months.cpp"])
    # run the compiled code
    output = subprocess.check_output("./a.exe")
    # print the output
    print("Output:", output.decode())

def delete_unaccessed():
    # Call your C++ function here
    import subprocess
    # compile the C++ code
    subprocess.call(["g++", "m_times.cpp"])
    # run the compiled code
    output = subprocess.check_output("./a.exe")
    # print the output
    print("Output:", output.decode())





def start_foldcleanernx():
    foldcleanernx_window = tk.Toplevel(foldercleaner)
    foldcleanernx_frame = tk.Frame(foldcleanernx_window, bg='light blue')
    foldcleanernx_frame.pack(fill='both', expand=True)

    header = tk.Label(foldcleanernx_frame, text="Folder Cleaner", font=("Helvetica", 16, "bold"), bg='light blue')
    header.pack(pady=10)

    button1 = tk.Button(foldcleanernx_frame, text="Delete Duplicate Files", command=delete_duplicates)
    button1.pack()

    button2 = tk.Button(foldcleanernx_frame, text="Delete Empty Files", command=delete_empty)
    button2.pack()

    button3 = tk.Button(foldcleanernx_frame, text="Delete Time Files", command=delete_time)
    button3.pack()

    button4 = tk.Button(foldcleanernx_frame, text="Delete Unaccessed Files", command=delete_unaccessed)
    button4.pack()

foldercleaner = tk.Tk()
foldercleaner.title("Folder Cleaner")

# Load your background image
image = Image.open("Bg for folder cleaner 6.png")
image = image.resize((foldercleaner.winfo_screenwidth(), foldercleaner.winfo_screenheight()))
bg_image = ImageTk.PhotoImage(image)

# Create a canvas for your background image
canvas = tk.Canvas(foldercleaner, width=foldercleaner.winfo_screenwidth(), height=foldercleaner.winfo_screenheight())
canvas.pack(fill='both', expand=True)
# Add the image to the canvas
canvas.create_image(0, 0, image=bg_image, anchor='nw')


# Add your text
canvas.create_text(foldercleaner.winfo_screenwidth()//2, foldercleaner.winfo_screenheight()//2, text="Hello, we are O(1)lympians", font=("Helvetica", 16, "bold"), justify='center', anchor='center')

# Create a button on the canvas to start the cleaner
start_button = tk.Button(foldercleaner, text="Start the Folder Cleaner", command=start_foldcleanernx)
canvas.create_window(foldercleaner.winfo_screenwidth()//2, foldercleaner.winfo_screenheight()//2 + 50, window=start_button)

foldercleaner.mainloop()
