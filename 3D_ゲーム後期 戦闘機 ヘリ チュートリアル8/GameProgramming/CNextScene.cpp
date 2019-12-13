#include"CNextScene.h"
//�L�����N�^�[�̃��X�g
std::vector<CTask*>CNextScene::mCharacters;
//�����������̃I�[�o�[���C�h
void CNextScene::Init(){
}
//�X�V�����̃I�[�o�[���C�h
void CNextScene::Update(){
	//�X�V����
	for (int i = 0; i<mCharacters.size(); i++){
		mCharacters[i]->Update();
	}
	//�Փˏ���
	Collision();
	//�`�揈��
	Render();
	//�폜����
	Remove();
}
//���̃V�[���̎擾
CScene::EScene CNextScene::GetNextScene(){
	return mScene;
}
/*
�J�����̐ݒ�
*/
void CNextScene::SetCamera(int left, int bottom){
	glMatrixMode(GL_PROJECTION);//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();//�s���������
	//2D��ʕ\���̈��ݒ�
	//��ʂ̍����W�C��ʂ̉E���W�C��ʂ̉����W�C��ʂ̏���W
	gluOrtho2D(
		left, left + DISP_W
		, bottom, bottom + DISP_H);//2D�̉�ʂ�ݒ�
	glMatrixMode(GL_MODELVIEW);//�s������f���r���[���[�h�֕ύX
}
void CNextScene::Collision(){
	for (int i = 0; i<mCharacters.size() - 1; i++){
		for (int j = i + 1; j<mCharacters.size(); j++){
			mCharacters[i]->Collision(mCharacters[i], mCharacters[j]);
			mCharacters[j]->Collision(mCharacters[j], mCharacters[i]);
		}
	}
}
void CNextScene::Render(){
	for (int i = 0; i<mCharacters.size(); i++){
		mCharacters[i]->Render();
	}
}
void CNextScene::Remove(){
	//�C�e���[�^�̐���
	std::vector<CTask*>::iterator itr;
	//�C�e���[�^��擪
	itr = mCharacters.begin();
	//�Ō�܂ŌJ��Ԃ�
	while (itr != mCharacters.end()){
		if ((*itr)->mEnabled){
			//����
			itr++;
		}
		else{
			//false�̃C���X�^���X���폜
			delete*itr;
			//���X�g������폜
			itr = mCharacters.erase(itr);
		}
	}
}
void CNextScene::Destroy(){
	for (int i = 0; i<mCharacters.size(); i++){
		delete mCharacters[i];
	}
	mCharacters.clear();
}