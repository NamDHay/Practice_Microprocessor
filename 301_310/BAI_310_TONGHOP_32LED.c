
//!#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_1_proteus.c>

unsigned INT8 i,j;
unsigned INT16 zt,zp;

void sang_tat_32led_5lan()
{
   FOR (j = 0; j < 5; j++)
   {
      xuat_32led_don_4byte (0, 0, 0, 0);
      delay_ms (200) ;
      xuat_32led_don_4byte (0xff, 0xff, 0xff, 0xff);
      delay_ms (200) ;
   }
}

void sang_tat_dan_tu_ngoai_vao_32led_2lan()
{
   FOR (j = 0; j < 2; j++)
   {
      FOR (i = 0; i < 16; i++)
      {
         xuat_32led_don_2word (zp, zt) ;
         delay_ms (200);
         zp = (zp<<1) + 1;
         zt = (zt>>1) + 0x8000;
      }

      FOR (i = 0; i < 16; i++)
      {
         xuat_32led_don_2word (zp, zt) ;
         delay_ms (200);
         zp = (zp<<1);
         zt = (zt>>1);
      }
   }
}

void sang_tat_dan_tu_trong_ra_32led_2lan()
{
   FOR (j = 0; j < 2; j++)
   {
      FOR (i = 0; i < 16; i++)
      {
         xuat_32led_don_2word (zp, zt) ;
         delay_ms (200);
         zp = (zp>>1) + 0x8000;
         zt = (zt<<1) + 1;
      }

      FOR (i = 0; i < 16; i++)
      {
         xuat_32led_don_2word (zp, zt) ;
         delay_ms (200);
         zp = (zp>>1);
         zt = (zt<<1);
      }
   }
}

void main()
{
   set_up_port_ic_chot () ;
   zp = 0;
   zt = 0;
   
   WHILE (true)
   {
      sang_tat_32led_5lan ();
      sang_tat_dan_tu_trong_ra_32led_2lan();
      sang_tat_32led_5lan ();
      sang_tat_dan_tu_ngoai_vao_32led_2lan();
   }
}

