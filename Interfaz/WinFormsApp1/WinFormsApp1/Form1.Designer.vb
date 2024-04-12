<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.bt_conec = New System.Windows.Forms.Button()
        Me.tb_ip = New System.Windows.Forms.TextBox()
        Me.tb_puerto = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.tb_planta = New System.Windows.Forms.TextBox()
        Me.Hora_riego = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'bt_conec
        '
        Me.bt_conec.Location = New System.Drawing.Point(108, 127)
        Me.bt_conec.Name = "bt_conec"
        Me.bt_conec.Size = New System.Drawing.Size(94, 29)
        Me.bt_conec.TabIndex = 0
        Me.bt_conec.Text = "Conectar"
        Me.bt_conec.UseVisualStyleBackColor = True
        '
        'tb_ip
        '
        Me.tb_ip.Location = New System.Drawing.Point(91, 34)
        Me.tb_ip.Name = "tb_ip"
        Me.tb_ip.Size = New System.Drawing.Size(125, 27)
        Me.tb_ip.TabIndex = 1
        '
        'tb_puerto
        '
        Me.tb_puerto.Location = New System.Drawing.Point(91, 81)
        Me.tb_puerto.Name = "tb_puerto"
        Me.tb_puerto.Size = New System.Drawing.Size(125, 27)
        Me.tb_puerto.TabIndex = 2
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(23, 34)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(24, 20)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "IP:"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(23, 88)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(55, 20)
        Me.Label2.TabIndex = 4
        Me.Label2.Text = "Puerto:"
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(395, 188)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(94, 29)
        Me.Button1.TabIndex = 5
        Me.Button1.Text = "Solicitar"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(320, 98)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(53, 20)
        Me.Label3.TabIndex = 6
        Me.Label3.Text = "Planta:"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(278, 142)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(95, 20)
        Me.Label4.TabIndex = 7
        Me.Label4.Text = "Ultima riego:"
        '
        'tb_planta
        '
        Me.tb_planta.Location = New System.Drawing.Point(379, 98)
        Me.tb_planta.Name = "tb_planta"
        Me.tb_planta.Size = New System.Drawing.Size(125, 27)
        Me.tb_planta.TabIndex = 8
        '
        'Hora_riego
        '
        Me.Hora_riego.Location = New System.Drawing.Point(379, 139)
        Me.Hora_riego.Name = "Hora_riego"
        Me.Hora_riego.Size = New System.Drawing.Size(125, 27)
        Me.Hora_riego.TabIndex = 9
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 20.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(516, 450)
        Me.Controls.Add(Me.Hora_riego)
        Me.Controls.Add(Me.tb_planta)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.tb_puerto)
        Me.Controls.Add(Me.tb_ip)
        Me.Controls.Add(Me.bt_conec)
        Me.Name = "Form1"
        Me.Text = "Conexion a servidor"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents bt_conec As Button
    Friend WithEvents tb_ip As TextBox
    Friend WithEvents tb_puerto As TextBox
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Button1 As Button
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents tb_planta As TextBox
    Friend WithEvents Hora_riego As TextBox
End Class
