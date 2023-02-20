import serial

ser = serial.Serial('COM3', 9600)

with open('sensor_data.txt', 'w') as file:
    while True:
        line = ser.readline().decode('utf-8').strip() # read a line from the serial port and decode it from bytes to string
        if line.startswith("Distance: "): # check if the line contains distance data
            distance_str = line.replace("Distance: ", "").replace(" cm", "") # extract the distance value from the line
            try:
                distance_cm = float(distance_str) # convert the distance value to a float
                print(distance_cm) # print the distance value to the console
                file.write(str(distance_cm) + "\n") # write the distance value to the file
            except ValueError:
                print("Invalid distance value:", distance_str)
        elif line:
            print(line) # print any other lines to the console
