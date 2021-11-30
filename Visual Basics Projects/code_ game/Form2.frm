VERSION 5.00
Object = "{0ECD9B60-23AA-11D0-B351-00A0C9055D8E}#6.0#0"; "MSHFLXGD.OCX"
Begin VB.Form Form2 
   Caption         =   "Form2"
   ClientHeight    =   8445
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   6420
   LinkTopic       =   "Form2"
   ScaleHeight     =   8445
   ScaleWidth      =   6420
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton box2 
      BackColor       =   &H8000000D&
      Caption         =   "Blue"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   3120
      Style           =   1  'Graphical
      TabIndex        =   5
      Top             =   1680
      Width           =   1815
   End
   Begin VB.CommandButton box 
      BackColor       =   &H000000FF&
      Caption         =   "Red"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Index           =   0
      Left            =   1080
      Style           =   1  'Graphical
      TabIndex        =   4
      Top             =   1680
      Width           =   1935
   End
   Begin MSHierarchicalFlexGridLib.MSHFlexGrid red 
      Height          =   3975
      Left            =   1080
      TabIndex        =   2
      Top             =   2760
      Width           =   2055
      _ExtentX        =   3625
      _ExtentY        =   7011
      _Version        =   393216
      BackColor       =   255
      Rows            =   8
      Cols            =   1
      FixedRows       =   0
      FixedCols       =   0
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      _NumberOfBands  =   1
      _Band(0).Cols   =   1
   End
   Begin VB.CommandButton button 
      Caption         =   "Start"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   5160
      TabIndex        =   1
      Top             =   7080
      Width           =   1095
   End
   Begin VB.TextBox text 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1215
      Left            =   1080
      MultiLine       =   -1  'True
      TabIndex        =   0
      Text            =   "Form2.frx":0000
      Top             =   360
      Width           =   3975
   End
   Begin MSHierarchicalFlexGridLib.MSHFlexGrid blue 
      Height          =   3975
      Left            =   3120
      TabIndex        =   3
      Top             =   2760
      Width           =   2055
      _ExtentX        =   3625
      _ExtentY        =   7011
      _Version        =   393216
      BackColor       =   -2147483635
      Rows            =   8
      Cols            =   1
      FixedRows       =   0
      FixedCols       =   0
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      _NumberOfBands  =   1
      _Band(0).Cols   =   1
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub box_Click(Index As Integer)
red.text = text.text
End Sub

Private Sub box2_Click()
blue.text = text.text
End Sub

Private Sub button_Click()

Form1.Visible = True
Unload Form2

Open "H:\Visual Basic\code game\gamefile\record.txt" For Output As #3

For Row = 0 To 6
    Write #3, red.TextMatrix(Row, 0),
Next Row
Write #3, ""

Close #3


End Sub

