object Form1: TForm1
  Left = 192
  Top = 124
  Width = 928
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 504
    Top = 200
    Width = 87
    Height = 13
    Caption = #1055#1086#1073#1077#1076#1080#1083' '#1048#1075#1088#1086#1082' 1'
    Visible = False
  end
  object StringGrid1: TStringGrid
    Left = 16
    Top = 8
    Width = 337
    Height = 337
    ColCount = 8
    DefaultColWidth = 40
    DefaultRowHeight = 40
    FixedCols = 0
    RowCount = 8
    FixedRows = 0
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = 40
    Font.Name = 'Arial Narrow'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnSelectCell = StringGrid1SelectCell
  end
  object Edit1: TEdit
    Left = 616
    Top = 64
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 616
    Top = 96
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit2'
  end
end
