[English version](README.md)

# Interaction Toolkit

Переиспользуемый плагин для Unreal Engine 5, который добавляет в любой проект систему взаимодействия и систему квестов.

## Что это

Interaction Toolkit — это плагин, который предоставляет две независимые системы:
1. **Система взаимодействия** — позволяет игроку взаимодействовать с объектами (двери, сундуки, NPC) через общий интерфейс.
2. **Система квестов** — отслеживает цели, прогресс и завершение с помощью HUD-трекера.

Плагин можно подключить к любому проекту UE5 и использовать без изменения исходного кода.

## Что реализовано

- **Система взаимодействия**
  - `IInteractionInterface` — общий интерфейс для интерактивных объектов
  - `UInteractionComponent` — находит ближайший интерактивный объект через `OverlapMultiByChannel`
  - UI-подсказка взаимодействия (`WBP_InteractionPrompt`)
  - Поиск по таймеру (10 раз в секунду)

- **Система квестов**
  - `UQuestData` — DataAsset для настройки квеста
  - `FQuestObjective` — структура для отдельной цели
  - `UQuestComponent` — отслеживает активные квесты и прогресс
  - HUD-трекер квестов (`WBP_QuestHUD`) — показывает активный квест, переключается на следующий, скрывается когда все завершены
  - Делегаты: `OnQuestCompleted`, `OnObjectiveProgress`

## Технологии

Unreal Engine 5.6, C++ (основная логика), Blueprint (UI), Enhanced Input (для демо).

## Как использовать

1. Скопируй папку `InteractionToolkit` в `Plugins/` твоего проекта.
2. Включи плагин в **Edit → Plugins → Interaction Toolkit**.
3. Перезапусти редактор.

### Взаимодействие

1. Реализуй `IInteractionInterface` на любом акторе (дверь, сундук, NPC).
2. Добавь `UInteractionComponent` на персонажа.
3. Укажи `Prompt Class` = `WBP_InteractionPrompt` в настройках компонента.

### Квесты

1. Создай DataAsset `UQuestData` (правой кнопкой → Miscellaneous → Data Asset → QuestData).
2. Добавь `UQuestComponent` на персонажа.
3. Укажи `Quest HUD Class` = `WBP_QuestHUD`.
4. Вызови `StartQuest`, чтобы начать квест.
5. Вызови `UpdateProgress`, когда цель выполнена.

## Скриншоты

![Подсказка взаимодействия](Docs/screenshot_interaction.jpg)
![HUD квестов](Docs/screenshot_quest.jpg)
![Уведомление "Quest Completed"](Docs/screenshot_notification.jpg)
![Дверь](Docs/screenshot_door.jpg)

## Скачать

[Ссылка на Google Drive](https://drive.google.com/file/d/19G90FR8aK15tyeaukxFMfoStj-7fWYFp/view?usp=sharing)

**Платформа:** Windows 64-bit  
Распакуй архив и запусти `InteractionDemo.exe`.

## Видео

[Демо плагина на YouTube](https://youtu.be/ew1aC2qPtEQ)

## Контакты

GitHub: [EduardNarezhnev](https://github.com/EduardNarezhnev)