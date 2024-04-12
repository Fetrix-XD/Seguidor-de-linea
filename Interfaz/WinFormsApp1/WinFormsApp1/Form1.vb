Imports System.Net.Sockets
Public Class Form1

    Dim cliente As TcpClient
    Dim enlace As NetworkStream
    Dim conectado As Boolean

    Private Sub bt_conec_Click(sender As Object, e As EventArgs) Handles bt_conec.Click
        Dim servidor As String = tb_ip.Text
        Dim puerto As String = tb_puerto.Text

        Try
            If Not conectado Then
                cliente = New TcpClient(servidor, puerto)
                enlace = cliente.GetStream() 'servidor conecta al servidor
                bt_conec.Text = "Desconectar"
                conectado = True
                tb_ip.Enabled = False
                tb_puerto.Enabled = False
            Else
                enlace.Close()
                cliente.Close()
                conectado = False
                tb_ip.Enabled = True
                tb_puerto.Enabled = True
                bt_conec.Text = "Conectar"
            End If

        Catch ex As SocketException
            MessageBox.Show("No se logro conexion (Revise ip y puerto)")
        End Try
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        If conectado Then
            Dim trama1 As String = "#" & tb_planta.Text
            Dim datowhat As Byte() = System.Text.Encoding.ASCII.GetBytes(trama1)
            enlace.Write(datowhat, 0, datowhat.Length)
            Dim datoIn(255) As Byte
            enlace.Read(datoIn, 0, datoIn.Length)
            Dim tramaEntrada As String = System.Text.Encoding.ASCII.GetString(datoIn)
            If tramaEntrada.Chars(0) = "%" Then
                tramaEntrada = Replace(tramaEntrada, "%", "")
                tramaEntrada = Replace(tramaEntrada, "(", "")
                tramaEntrada = Replace(tramaEntrada, ")", "")
                tramaEntrada = Replace(tramaEntrada, "[", "")
                tramaEntrada = Replace(tramaEntrada, "]", "")
                tramaEntrada = Replace(tramaEntrada, "'", "")
                tramaEntrada = Replace(tramaEntrada, ",", "")
                Hora_riego.Text = tramaEntrada
            End If
        End If
    End Sub
End Class
