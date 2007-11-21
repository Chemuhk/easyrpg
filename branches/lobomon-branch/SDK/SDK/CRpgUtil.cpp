/**
	@file
	@brief		ストリームを介せずにバッファから直接データを操作する
	@author		sue445
*/
#include "CRpgUtil.h"
#include "CRpgIOBase.h"


//=============================================================================
/**
	バッファから直接データを取得

	@param	buf			[in] 入力元バッファ

	@return				取得したバッファ
*/
//=============================================================================
smart_buffer CRpgUtil::GetData(const smart_buffer& buf)
{
	CRpgIOBase st;
	smart_buffer temp;

	return (st.OpenFromMemory(buf.GetConstPtr(), buf.GetSize())) ? st.ReadData() : temp;
}

//=============================================================================
/**
	バッファから文字列を取得

	@param	buf			[in] 入力元バッファ

	@return				取得した文字列
*/
//=============================================================================
string CRpgUtil::GetString(const smart_buffer& buf)
{
	CRpgIOBase st;

	return (st.OpenFromMemory(buf.GetConstPtr(), buf.GetSize())) ? st.ReadString() : "";
}

//=============================================================================
/**
	ツクール仕様の1次元配列を読み込む

	@param	buf		[in] 入力元バッファ

	@return			取得した1次元配列
*/
//=============================================================================
CRpgArray1 CRpgUtil::GetArray1(const smart_buffer& buf)
{
	int col,size=0;
	CRpgIOBase		st;
	CRpgArray1		array;


	// バッファが初期化されていない
	if(buf.GetSize()==0)		return array;

	// 読み込み用ストリームの初期化
	st.OpenFromMemory(buf.GetConstPtr(), buf.GetSize());

	// データを格納する
	while(!st.IsEof()){
		col = st.ReadBerNumber();
	//	printf("\n  columnas %d ",col); 
		if(col==0)	break;
		array.SetData(col, st.ReadData());
		size=(array.GetString(col)).size();
   //     printf(" tama�o %d ",size); 
     //   if(size<5)
    //    printf(" numero %d ",array.GetNumber(col));
    //    printf((array.GetString(col)).c_str());
	}

	return array;
}

//=============================================================================
/**
	ツクール仕様の2次元配列を読み込む

	@param	buf		[in] 入力元バッファ

	@return			取得した2次元配列
*/
//=============================================================================
CRpgArray2 CRpgUtil::GetArray2(const smart_buffer& buf)
{
	int row, col, max,size;
	CRpgIOBase		st;
	CRpgArray2		array;
	// バッファが初期化されていない
	if(buf.GetSize()==0)		return array;
	// 読み込み用ストリームの初期化
	st.OpenFromMemory(buf.GetConstPtr(), buf.GetSize());
	// 一番最初には配列のサイズが格納されている
	max = st.ReadBerNumber();
	// データを格納する
	while(!st.IsEof()){
		row = st.ReadBerNumber();
		for(;;){
			col = st.ReadBerNumber();
	//		printf("\n  filas %d m columnas %d ",row,col); 
			if(col==0)	break;
			array.SetData(row, col, st.ReadData());
		size= (array.GetString(row,col)).size();
	//	printf(" tama�o %d ",size); 
     //   if(size<5)
      //  printf(" numero %d ",array.GetNumber(row,col));
      //  printf((array.GetString(row,col)).c_str());
		}
	}

	return array;
}

int CRpgUtil::get_set_sizeused(int size, bool rw)
{ static int  sizeused=0;
 if(rw)//verdadero lee
return (sizeused);
else//falso escribe
{sizeused=size;
return (sizeused);
}

}


CRpgArray2 CRpgUtil::GetArray2_1(const smart_buffer& buf)//aqui esta la salvacion
{
	int row, col, max,actual;
	CRpgIOBase		st;
	CRpgArray2		array;
    bool exit =false;
    int size=0;
	// si el tam�o es insuficiente
	if(buf.GetSize()==0)		return array;
	// 読み込み用ストリームの初期化
	st.OpenFromMemory(buf.GetConstPtr(), buf.GetSize());
     // printf("\n  constante %d  tama�o %d ",buf.GetConstPtr(), buf.GetSize()); 
	// saca el maximo del archivo
    //	max = st.ReadBerNumber();

	// データを格納する
	while((!st.IsEof())&&(!exit)) {
		row = st.ReadBerNumber();
		size++;
        for(;;){
			col = st.ReadBerNumber();
			size++;
          //  printf("\n  filas %d m columnas %d ",row,col); 
			if(col==0)	break;
			array.SetData(row, col, st.ReadData());
		//	printf(((array.GetString(row,col)).c_str()));
	        actual=(array.GetString(row,col)).size();
          //  printf(" tama�o %d ",actual); 
            size=size+actual+1;
            //   printf(" tama�o acumulado %d ",size); 
          
       //     if(actual<5)
       // printf(" numero %d ",array.GetNumber(row,col));
        
            if(col==51){
            exit=true;
            break;}// si lees el ultimo dato
    	}
	}
 get_set_sizeused(size,0);
	return array;
}
