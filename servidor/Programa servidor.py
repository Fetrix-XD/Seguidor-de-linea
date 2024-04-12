import socket
import sys
import threading
import mysql.connector
import datetime

bbdd = mysql.connector.connect(host='localhost', user='root', password='1234')
cursor = bbdd.cursor()

def hilo_cliente(conn, cliente):
    try:
        print('Conexion desde: {}:{}'.format(*cliente))

        while True:
            data = conn.recv(255)
            print('Se recibio: ', data.decode())
            if data:
                print('{}:{}'.format(*cliente), data.decode())
                msg = str(data.decode())
                if(msg.find("#")!=-1):
                    id = int(msg[1])
                    print(id)
                    comando = 'SELECT Hora_Rirgo FROM proy.plant_r WHERE Planta>
                    cursor.execute(comando)
                    datos1 = cursor.fetchall()
                    print(datos1)
                    trama = "%"+str(datos1)
                    conn.send(trama.encode())
                elif(msg.find("$")!=-1):
                    trama = msg.replace('$',' ')
                    datos = trama.split('_')
                    var = int(datos[1])
                    ahora = datetime.datetime.now()
                    hora_a = ahora.strftime('%H:%M:%S')
                    comando = 'INSERT INTO proy.plant_r (Planta, Hora_Rirgo)VAL>
                    comando = comando.format(var, hora_a)
                    cursor.execute(comando)
                    bbdd.commit()
                    print(var)
                else:
                    conn.send("!ERR".encode())

            else:
               break
    finally:
        conn.close()
    print('Conexion cerrada desde: {}:{}'.format(*cliente))
    return
puerto = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
direccion = ('192.168.1.108', 1409)
puerto.bind(direccion)
print('Servicio habilitado en{}:{}'.format(*direccion))
puerto.listen(1)

hilos = []
cont = 0
while True:
    print('Esperando conexion entrante')
    conn, cliente = puerto.accept()
    cont = cont+1
    hilos.append( threading.Thread(name=('conexion'+str(cont)),target=hilo_clie>
    hilos[cont-1].start()
