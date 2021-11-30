VERSION 5.00
Object = "{0ECD9B60-23AA-11D0-B351-00A0C9055D8E}#6.0#0"; "MSHFLXGD.OCX"
Begin VB.Form Form3 
   BackColor       =   &H000080FF&
   Caption         =   "Form3"
   ClientHeight    =   8280
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   6060
   LinkTopic       =   "Form3"
   ScaleHeight     =   8280
   ScaleWidth      =   6060
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton new 
      BackColor       =   &H0000FFFF&
      Caption         =   "Join a game"
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
      Left            =   360
      Style           =   1  'Graphical
      TabIndex        =   5
      Top             =   7080
      Width           =   1095
   End
   Begin MSHierarchicalFlexGridLib.MSHFlexGrid team 
      Height          =   3975
      Left            =   960
      TabIndex        =   4
      Top             =   2760
      Width           =   3975
      _ExtentX        =   7011
      _ExtentY        =   7011
      _Version        =   393216
      Rows            =   8
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
      _Band(0).Cols   =   2
   End
   Begin VB.TextBox text 
      BackColor       =   &H00FFFFC0&
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
      Left            =   960
      MultiLine       =   -1  'True
      TabIndex        =   3
      Text            =   "Form3.frx":0000
      Top             =   240
      Width           =   3975
   End
   Begin VB.CommandButton start 
      BackColor       =   &H00FF00FF&
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
      Left            =   4560
      Style           =   1  'Graphical
      TabIndex        =   2
      Top             =   7080
      Width           =   1095
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
      Left            =   960
      Style           =   1  'Graphical
      TabIndex        =   1
      Top             =   1680
      Width           =   1935
   End
   Begin VB.CommandButton box 
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
      Index           =   1
      Left            =   3000
      Style           =   1  'Graphical
      TabIndex        =   0
      Top             =   1680
      Width           =   1815
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub box_Click(Index As Integer)

If text.text <> "Please enter your teamates'names." Then
    For Row = 7 To 0 Step -1
        If team.TextMatrix(Row, Index) = "" Then Where = Row
    Next Row
    team.TextMatrix(Where, Index) = text.text
    
    text.text = "Please enter your teamates'names."
End If


End Sub

Private Sub Form_Load()
Form1.Picture = LoadPicture("H:\Visual Basic\code game\resources\interface.jpg")
text.text = "Please enter your teamates'names."
End Sub

Private Sub new_Click()
Open "H:\Visual Basic\code game\gamefile\record.txt" For Output As #4
Close #4

Form1.Visible = True
Unload Form3
End Sub

Private Sub start_Click()

Open "H:\Visual Basic\code game\gamefile\record.txt" For Output As #3

For colomn = 0 To 1
    For Row = 0 To 7
        Write #3, team.TextMatrix(Row, colomn),
    Next Row
    Write #3,
Next colomn

Close #3

Form1.Visible = True
Unload Form3
End Sub

